#include <omnetpp.h>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "QueryMsg_m.h"

using namespace omnetpp;

class NothingNode : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleQueryMessage(QueryMsg *msg);
    virtual void handleQueryResp(QueryResp *msg);
};

Define_Module(NothingNode);

void NothingNode::handleQueryResp(QueryResp *msg)
{
    int current_ind = msg->getIndex();
    msg->setIndex(++current_ind);
    //EV << "Nothing recieved message: " << msg->getIndex() << " also " << current_ind << "\n";

    int gateIndex = msg->getGate_paths(current_ind);
    send(msg, "gate$o", gateIndex);
}

void NothingNode::handleQueryMessage(QueryMsg *msg)
{

    int current_ind = msg->getIndex();
    int fromGateInd = msg->getArrivalGate()->getIndex();
    msg->setFrom_gates(msg->getLength() - 1 - current_ind, fromGateInd);

    msg->setIndex(++current_ind);
    //EV << "Nothing recieved message: " << msg->getIndex() << " also " << current_ind << "\n";

    int gateIndex = msg->getGate_paths(current_ind);
    send(msg, "gate$o", gateIndex);
}

void NothingNode::initialize()
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
}

void NothingNode::handleMessage(cMessage *msg)
{
    QueryMsg *queryMsg = dynamic_cast<QueryMsg*>(msg);
    QueryResp *queryResp = dynamic_cast<QueryResp*>(msg);

    if (queryMsg)
        handleQueryMessage(queryMsg);
    else if(queryResp)
        handleQueryResp(queryResp);
}
