#include <omnetpp.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "QueryMsg_m.h"
#include <sqlite3.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <string>
#include "TestSettings.h"


using namespace omnetpp;
using namespace std;

class ClientNode : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleQueryResp(QueryResp *from);
    virtual void handleQueryMessage(QueryMsg *msg);
    virtual QueryMsg * CreateQueryMessage(int server_num);
    std::string lattitude;

    int currentFile;
    int maxFile;

    int server2File;
};

Define_Module(ClientNode);

void ClientNode::handleQueryResp(QueryResp *from)
{

    QueryMsg *msg = CreateQueryMessage(from->getServer_id());
    if(!msg)
        return ;

    int current_ind = msg->getIndex();
    int gateIndex = msg->getGate_paths(current_ind);


    send(msg, "gate$o", gateIndex);
}

void ClientNode::handleQueryMessage(QueryMsg *msg)
{
}

void ClientNode::handleMessage(cMessage *msg)
{
    QueryMsg *queryMsg = dynamic_cast<QueryMsg*>(msg);
    QueryResp *queryResp = dynamic_cast<QueryResp*>(msg);

    if (queryMsg)
        handleQueryMessage(queryMsg);
    else if(queryResp)
        handleQueryResp(queryResp);

    delete msg;
}

void ClientNode::initialize()
{
    std::string garbage = par("d29").stringValue();
    std::string garbage2 = par("d32").stringValue();


    lattitude = par("d30").stringValue();
    std::string longitude = par("d33").stringValue();

    double y = ((stod(lattitude) + 90) * 2) + atol(this->getDisplayString().getTagArg("p", 1));
    double x = ((stod(longitude) + 180) * 2) + atol(this->getDisplayString().getTagArg("p", 0));

    this->getDisplayString().setTagArg("p", 0, x);
    this->getDisplayString().setTagArg("p", 1, y);

    std::string Country = par("d31").stringValue();

    std::string location = par("d34").stringValue();
    std::string nodeType = par("d35").stringValue();
    std::string color = par("d36").stringValue();

    currentFile = 0;
    server2File = 0;
    maxFile = 23;

    #ifdef GLOBAL_TEST
        QueryMsg *msg = CreateQueryMessage(0);
        int current_ind = msg->getIndex();
        int gateIndex = msg->getGate_paths(current_ind);

        send(msg, "gate$o", gateIndex);

        #ifdef MULTI_SERVER
            msg = CreateQueryMessage(1);
            current_ind = msg->getIndex();
            gateIndex = msg->getGate_paths(current_ind);

            send(msg, "gate$o", gateIndex);
        #endif
    #endif


}


QueryMsg * ClientNode::CreateQueryMessage(int server_num)
{
    #ifdef THROUGHPUT_TEST
        if(!server_num && currentFile >= 22){
            ofstream file("completed.txt", ios_base::app);
            file << "Client completed server 0 " << this->getName() << " at time " << simTime() << endl;

            file.close();

            return NULL;
        }
        else if(server_num && server2File >= 22){
            ofstream file("completed.txt", ios_base::app);
            file << "Client completed server 1 " << this->getName() << " at time " << simTime() << endl;

            file.close();

            return NULL;
        }
    #endif

    string fileName;

    if(!server_num){
        currentFile = (currentFile + 1) % maxFile;
        currentFile = currentFile <= 0 ? currentFile = 1 : currentFile;

        fileName = "/home/me/Desktop/omnetpp-6.0.1/samples/TPCH/TPCH_Test/Query/q" + std::to_string(currentFile) + ".sql";
    }
    else{
        server2File = (server2File + 1) % maxFile;
        server2File = server2File <= 0 ? server2File = 1 : server2File;

        fileName = "/home/me/Desktop/omnetpp-6.0.1/samples/TPCH/TPCH_Test/Query/q" + std::to_string(server2File) + ".sql";
    }


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
    msg->setMESSAGE(fileContents.c_str());
    msg->setIndex(0);

    #ifdef MULTI_CLIENT_ORIG
        if(!server_num && "38.89511" == lattitude) // node 2
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,2);
        }
        else if(!server_num && "32.71533" == lattitude) // node 8
        {
            msg->setLength(4);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,0);
            msg->setGate_paths(2,1);
            msg->setGate_paths(3,2);
        }
        else if(!server_num && "40.76078" == lattitude) // node 18
        {
            msg->setLength(5);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,0);
            msg->setGate_paths(3,0);
            msg->setGate_paths(4,2);
        }
        else if(!server_num && "39.95622" == lattitude) // node 24
        {
            msg->setLength(5);
            msg->setGate_paths(0,1);
            msg->setGate_paths(1,1);
            msg->setGate_paths(2,0);
            msg->setGate_paths(3,2);
            msg->setGate_paths(4,2);
        }

        if(server_num && "38.89511" == lattitude) // node 2
        {
            msg->setLength(5);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,3);
            msg->setGate_paths(3,0);
            msg->setGate_paths(4,2);
        }
        else if(server_num && "32.71533" == lattitude) // node 8
        {
            msg->setLength(2);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
        }
        else if(server_num && "40.76078" == lattitude) // node 18
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,0);
            msg->setGate_paths(2,0);
        }
        else if(server_num && "39.95622" == lattitude) // node 24
        {
            msg->setLength(2);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
        }
    #endif

    #ifdef MULTI_CLIENT_NEW
        if(!server_num && "38.89511" == lattitude) // node 2
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,2);
        }
        else if(!server_num && "32.71533" == lattitude) // node 8
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,2);
        }
        else if(!server_num && "40.76078" == lattitude) // node 18
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,2);
        }
        else if(!server_num && "39.95622" == lattitude) // node 24
        {
            msg->setLength(5);
            msg->setGate_paths(0,1);
            msg->setGate_paths(1,1);
            msg->setGate_paths(2,0);
            msg->setGate_paths(3,2);
            msg->setGate_paths(4,2);
        }


        if(server_num && "38.89511" == lattitude) // node 2
        {
            msg->setLength(5);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,2);
            msg->setGate_paths(2,3);
            msg->setGate_paths(3,1);
            msg->setGate_paths(4,2);
        }
        else if(server_num && "32.71533" == lattitude) // node 8
        {
            msg->setLength(2);
            msg->setGate_paths(0,1);
            msg->setGate_paths(1,2);
        }
        else if(server_num && "40.76078" == lattitude) // node 18
        {
            msg->setLength(3);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,1);
            msg->setGate_paths(2,2);
        }
        else if(server_num && "39.95622" == lattitude) // node 24
        {
            msg->setLength(4);
            msg->setGate_paths(0,0);
            msg->setGate_paths(1,0);
            msg->setGate_paths(2,1);
            msg->setGate_paths(3,2);
        }


    #endif

    return msg;
}
