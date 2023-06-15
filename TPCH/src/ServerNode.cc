#include <sqlite3.h>
#include <omnetpp.h>
#include <stdio.h>
#include "QueryMsg_m.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <queue>
#include <chrono>
#include "TestSettings.h"



using namespace omnetpp;
using namespace std;

class ServerNode : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleQueryMessage(QueryMsg *msg);
    virtual QueryResp * CreateResponse(QueryMsg *from);
    virtual void baseLinePowerTest();
    virtual void baseLineThroughputTest();

    sqlite3* db;

    std::queue<QueryMsg*> msgQueue;
    std::queue<QueryResp *> toSendQ;

    bool isBusy = false;
    cMessage *endProcessingEvent;

    double processingTime;
    int multiplex_num;

    int server_id;

    unsigned long long num_gets_satisfied;
};

Define_Module(ServerNode);

void reset_file(const char *filename);

void ServerNode::handleMessage(cMessage *msg)
{
    QueryMsg *queryMsg = dynamic_cast<QueryMsg*>(msg);

    if (msg == endProcessingEvent) {
        isBusy = false;

        //EV << "HEY" << std::endl;

        if (!msgQueue.empty()) {
            QueryMsg *nextMsg = msgQueue.front();
            msgQueue.pop();
            handleQueryMessage(nextMsg);
            delete nextMsg;
        }

        QueryResp *toSend = toSendQ.front();
        toSendQ.pop();
        int gateIndex = toSend->getGate_paths(toSend->getIndex());
        send(toSend, "gate$o", gateIndex);
        ++num_gets_satisfied;
        EV << "Server " << server_id << " Has done " << num_gets_satisfied << " queries at time " << simTime() << endl;
    }
    else if (queryMsg) {
        if (isBusy){
            msgQueue.push(queryMsg);
        }
        else{
            handleQueryMessage(queryMsg);
            delete msg;
        }
    }

}

void ServerNode::handleQueryMessage(QueryMsg *msg)
{
    int current_ind = msg->getIndex();
    int fromGateInd = msg->getArrivalGate()->getIndex();
    msg->setFrom_gates(msg->getLength() - 1 - current_ind, fromGateInd);
    msg->setIndex(++current_ind);

    int length = msg->getLength();

    QueryResp *toSend = CreateResponse(msg);

    toSendQ.push(toSend);


    isBusy = true;
    scheduleAt(simTime() + processingTime, endProcessingEvent);

}



QueryResp * ServerNode::CreateResponse(QueryMsg *from)
{
    const char* sql = (from->getMESSAGE());
    sqlite3_stmt* stmt;

    auto start = std::chrono::high_resolution_clock::now();

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot get query: " << sql << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        exit(1);
    }

    std::string result;

    rc = sqlite3_step(stmt);
    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        int cols = sqlite3_column_count(stmt);
        for (int col = 0; col < cols; col++)
        {
            const char * val = reinterpret_cast<const char*>(sqlite3_column_text(stmt, col));
            if (val != nullptr)
                result += val;
            if (col < cols - 1)
                result += ", ";
        }
        result += "\n";
        rc = sqlite3_step(stmt);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    processingTime = static_cast<double>(duration.count());

    EV << processingTime << " seconds" << std::endl;
    //EV << result << std::endl;

    QueryResp *msg = new QueryResp("Server message");

    msg->setMESSAGE(result.c_str());
    msg->setIndex(0);
    msg->setLength(from->getLength());
    msg->setServer_id(server_id);
    for(int i = 0; i < msg->getLength(); i++)
    {
        msg->setGate_paths(i, from->getFrom_gates(i));
    }

    return msg;
}

void ServerNode::initialize()
{
    std::string garbage = par("d29").stringValue();
    std::string garbage2 = par("d32").stringValue();


    std::string lattitude = par("d30").stringValue();
    std::string longitude = par("d33").stringValue();

    double y = ((stod(lattitude) + 90) * 2) + atol(this->getDisplayString().getTagArg("p", 1));
    double x = ((stod(longitude) + 180) * 2) + atol(this->getDisplayString().getTagArg("p", 0));

    this->getDisplayString().setTagArg("p", 0, x);
    this->getDisplayString().setTagArg("p", 1, y);

    std::string Country = par("d31").stringValue();

    std::string location = par("d34").stringValue();
    std::string nodeType = par("d35").stringValue();
    std::string color = par("d36").stringValue();


    char currentPath[PATH_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        EV << "Current working directory is: " << currentPath << std::endl;
    } else {
        EV << "getcwd() error" << std::endl;
    }

    int rc = sqlite3_open("/home/me/Desktop/omnetpp-6.0.1/samples/TPCH/TPCH_Test/TPCH-sqlite/TPC-H.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }

    if(lattitude == "37.35411"){
        server_id = 1;
    }
    else{
        server_id = 0;
    }

    endProcessingEvent = new cMessage("endProcessing");
    processingTime = 0.001;

    int multiplex_num = 2;
    num_gets_satisfied = 0;

    #ifndef GLOBAL_TEST
        #ifdef POWER_TEST
            baseLinePowerTest();
        #elif defined(THROUGHPUT_TEST)
            baseLineThroughputTest();
        #endif
    #endif
            reset_file("completed.txt");
}

void ServerNode::baseLineThroughputTest(){
    EV << "SERVER ONLY THROUGHPUT TEST STARTED" << endl;

    double total_time = 0;


    for(int i = 1; i <= 22; i++){
        for(int stream = 0; stream < NUM_STREAMS; stream++){
            string fileName = "/home/me/Desktop/omnetpp-6.0.1/samples/TPCH/TPCH_Test/Query/q" + std::to_string(i) + ".sql";

            //EV << fileName << std::endl;

            std::ifstream file(fileName);

            if (!file) {
                std::cerr << "Failed to open file: " << fileName << std::endl;
            }

            std::stringstream buffer;
            buffer << file.rdbuf();

            std::string fileContents = buffer.str();
            //EV << "HEY " << buffer.str() << std::endl;

            QueryMsg *msg = new QueryMsg("Client Message");
            total_time += processingTime;

            msg->setMESSAGE(fileContents.c_str());
            msg->setIndex(0);

            QueryResp *resp = CreateResponse(msg);

            delete resp;
            delete msg;
        }
    }

    EV << "Throughput Test completed in " << total_time << " seconds with " << NUM_STREAMS << " streams." << endl;
}

void ServerNode::baseLinePowerTest(){
    EV << "SERVER ONLY POWER TEST STARTED" << endl;

    double total_time = 0;

    for(int i = 1; i <= 22; i++){
        string fileName = "/home/me/Desktop/omnetpp-6.0.1/samples/TPCH/TPCH_Test/Query/q" + std::to_string(i) + ".sql";

        //EV << fileName << std::endl;

        std::ifstream file(fileName);

        if (!file) {
            std::cerr << "Failed to open file: " << fileName << std::endl;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string fileContents = buffer.str();
        //EV << "HEY " << buffer.str() << std::endl;

        QueryMsg *msg = new QueryMsg("Client Message");
        total_time += processingTime;

        msg->setMESSAGE(fileContents.c_str());
        msg->setIndex(0);

        QueryResp *resp = CreateResponse(msg);

        delete resp;
        delete msg;
    }

    EV << "Power Test completed in " << total_time << " seconds. " << endl;
}

void reset_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL)
        fclose(file);
}

