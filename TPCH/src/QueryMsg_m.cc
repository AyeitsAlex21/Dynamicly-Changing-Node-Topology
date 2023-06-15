//
// Generated file, do not edit! Created by opp_msgtool 6.0 from QueryMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "QueryMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(QueryMsg)

QueryMsg::QueryMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

QueryMsg::QueryMsg(const QueryMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

QueryMsg::~QueryMsg()
{
}

QueryMsg& QueryMsg::operator=(const QueryMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void QueryMsg::copy(const QueryMsg& other)
{
    for (size_t i = 0; i < 10; i++) {
        this->gate_paths[i] = other.gate_paths[i];
    }
    for (size_t i = 0; i < 10; i++) {
        this->from_gates[i] = other.from_gates[i];
    }
    this->index = other.index;
    this->length = other.length;
    this->MESSAGE = other.MESSAGE;
}

void QueryMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimArrayPacking(b,this->gate_paths,10);
    doParsimArrayPacking(b,this->from_gates,10);
    doParsimPacking(b,this->index);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->MESSAGE);
}

void QueryMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->gate_paths,10);
    doParsimArrayUnpacking(b,this->from_gates,10);
    doParsimUnpacking(b,this->index);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->MESSAGE);
}

size_t QueryMsg::getGate_pathsArraySize() const
{
    return 10;
}

int QueryMsg::getGate_paths(size_t k) const
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    return this->gate_paths[k];
}

void QueryMsg::setGate_paths(size_t k, int gate_paths)
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    this->gate_paths[k] = gate_paths;
}

size_t QueryMsg::getFrom_gatesArraySize() const
{
    return 10;
}

int QueryMsg::getFrom_gates(size_t k) const
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    return this->from_gates[k];
}

void QueryMsg::setFrom_gates(size_t k, int from_gates)
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    this->from_gates[k] = from_gates;
}

int QueryMsg::getIndex() const
{
    return this->index;
}

void QueryMsg::setIndex(int index)
{
    this->index = index;
}

int QueryMsg::getLength() const
{
    return this->length;
}

void QueryMsg::setLength(int length)
{
    this->length = length;
}

const char * QueryMsg::getMESSAGE() const
{
    return this->MESSAGE.c_str();
}

void QueryMsg::setMESSAGE(const char * MESSAGE)
{
    this->MESSAGE = MESSAGE;
}

class QueryMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_gate_paths,
        FIELD_from_gates,
        FIELD_index,
        FIELD_length,
        FIELD_MESSAGE,
    };
  public:
    QueryMsgDescriptor();
    virtual ~QueryMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(QueryMsgDescriptor)

QueryMsgDescriptor::QueryMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(QueryMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

QueryMsgDescriptor::~QueryMsgDescriptor()
{
    delete[] propertyNames;
}

bool QueryMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<QueryMsg *>(obj)!=nullptr;
}

const char **QueryMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *QueryMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int QueryMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int QueryMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_gate_paths
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_from_gates
        FD_ISEDITABLE,    // FIELD_index
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_MESSAGE
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *QueryMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "gate_paths",
        "from_gates",
        "index",
        "length",
        "MESSAGE",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int QueryMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "gate_paths") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "from_gates") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "index") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "length") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "MESSAGE") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *QueryMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_gate_paths
        "int",    // FIELD_from_gates
        "int",    // FIELD_index
        "int",    // FIELD_length
        "string",    // FIELD_MESSAGE
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **QueryMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *QueryMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int QueryMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return 10;
        case FIELD_from_gates: return 10;
        default: return 0;
    }
}

void QueryMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'QueryMsg'", field);
    }
}

const char *QueryMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string QueryMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return long2string(pp->getGate_paths(i));
        case FIELD_from_gates: return long2string(pp->getFrom_gates(i));
        case FIELD_index: return long2string(pp->getIndex());
        case FIELD_length: return long2string(pp->getLength());
        case FIELD_MESSAGE: return oppstring2string(pp->getMESSAGE());
        default: return "";
    }
}

void QueryMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: pp->setGate_paths(i,string2long(value)); break;
        case FIELD_from_gates: pp->setFrom_gates(i,string2long(value)); break;
        case FIELD_index: pp->setIndex(string2long(value)); break;
        case FIELD_length: pp->setLength(string2long(value)); break;
        case FIELD_MESSAGE: pp->setMESSAGE((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryMsg'", field);
    }
}

omnetpp::cValue QueryMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return pp->getGate_paths(i);
        case FIELD_from_gates: return pp->getFrom_gates(i);
        case FIELD_index: return pp->getIndex();
        case FIELD_length: return pp->getLength();
        case FIELD_MESSAGE: return pp->getMESSAGE();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'QueryMsg' as cValue -- field index out of range?", field);
    }
}

void QueryMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: pp->setGate_paths(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_from_gates: pp->setFrom_gates(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_index: pp->setIndex(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_length: pp->setLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MESSAGE: pp->setMESSAGE(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryMsg'", field);
    }
}

const char *QueryMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr QueryMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void QueryMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryMsg *pp = omnetpp::fromAnyPtr<QueryMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryMsg'", field);
    }
}

Register_Class(QueryResp)

QueryResp::QueryResp(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

QueryResp::QueryResp(const QueryResp& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

QueryResp::~QueryResp()
{
}

QueryResp& QueryResp::operator=(const QueryResp& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void QueryResp::copy(const QueryResp& other)
{
    for (size_t i = 0; i < 10; i++) {
        this->gate_paths[i] = other.gate_paths[i];
    }
    this->index = other.index;
    this->length = other.length;
    this->MESSAGE = other.MESSAGE;
    this->server_id = other.server_id;
}

void QueryResp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimArrayPacking(b,this->gate_paths,10);
    doParsimPacking(b,this->index);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->MESSAGE);
    doParsimPacking(b,this->server_id);
}

void QueryResp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimArrayUnpacking(b,this->gate_paths,10);
    doParsimUnpacking(b,this->index);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->MESSAGE);
    doParsimUnpacking(b,this->server_id);
}

size_t QueryResp::getGate_pathsArraySize() const
{
    return 10;
}

int QueryResp::getGate_paths(size_t k) const
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    return this->gate_paths[k];
}

void QueryResp::setGate_paths(size_t k, int gate_paths)
{
    if (k >= 10) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)10, (unsigned long)k);
    this->gate_paths[k] = gate_paths;
}

int QueryResp::getIndex() const
{
    return this->index;
}

void QueryResp::setIndex(int index)
{
    this->index = index;
}

int QueryResp::getLength() const
{
    return this->length;
}

void QueryResp::setLength(int length)
{
    this->length = length;
}

const char * QueryResp::getMESSAGE() const
{
    return this->MESSAGE.c_str();
}

void QueryResp::setMESSAGE(const char * MESSAGE)
{
    this->MESSAGE = MESSAGE;
}

int QueryResp::getServer_id() const
{
    return this->server_id;
}

void QueryResp::setServer_id(int server_id)
{
    this->server_id = server_id;
}

class QueryRespDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_gate_paths,
        FIELD_index,
        FIELD_length,
        FIELD_MESSAGE,
        FIELD_server_id,
    };
  public:
    QueryRespDescriptor();
    virtual ~QueryRespDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(QueryRespDescriptor)

QueryRespDescriptor::QueryRespDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(QueryResp)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

QueryRespDescriptor::~QueryRespDescriptor()
{
    delete[] propertyNames;
}

bool QueryRespDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<QueryResp *>(obj)!=nullptr;
}

const char **QueryRespDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *QueryRespDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int QueryRespDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int QueryRespDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,    // FIELD_gate_paths
        FD_ISEDITABLE,    // FIELD_index
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_MESSAGE
        FD_ISEDITABLE,    // FIELD_server_id
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *QueryRespDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "gate_paths",
        "index",
        "length",
        "MESSAGE",
        "server_id",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int QueryRespDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "gate_paths") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "index") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "length") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "MESSAGE") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "server_id") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *QueryRespDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_gate_paths
        "int",    // FIELD_index
        "int",    // FIELD_length
        "string",    // FIELD_MESSAGE
        "int",    // FIELD_server_id
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **QueryRespDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *QueryRespDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int QueryRespDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return 10;
        default: return 0;
    }
}

void QueryRespDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'QueryResp'", field);
    }
}

const char *QueryRespDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string QueryRespDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return long2string(pp->getGate_paths(i));
        case FIELD_index: return long2string(pp->getIndex());
        case FIELD_length: return long2string(pp->getLength());
        case FIELD_MESSAGE: return oppstring2string(pp->getMESSAGE());
        case FIELD_server_id: return long2string(pp->getServer_id());
        default: return "";
    }
}

void QueryRespDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: pp->setGate_paths(i,string2long(value)); break;
        case FIELD_index: pp->setIndex(string2long(value)); break;
        case FIELD_length: pp->setLength(string2long(value)); break;
        case FIELD_MESSAGE: pp->setMESSAGE((value)); break;
        case FIELD_server_id: pp->setServer_id(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryResp'", field);
    }
}

omnetpp::cValue QueryRespDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: return pp->getGate_paths(i);
        case FIELD_index: return pp->getIndex();
        case FIELD_length: return pp->getLength();
        case FIELD_MESSAGE: return pp->getMESSAGE();
        case FIELD_server_id: return pp->getServer_id();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'QueryResp' as cValue -- field index out of range?", field);
    }
}

void QueryRespDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        case FIELD_gate_paths: pp->setGate_paths(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_index: pp->setIndex(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_length: pp->setLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_MESSAGE: pp->setMESSAGE(value.stringValue()); break;
        case FIELD_server_id: pp->setServer_id(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryResp'", field);
    }
}

const char *QueryRespDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr QueryRespDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void QueryRespDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    QueryResp *pp = omnetpp::fromAnyPtr<QueryResp>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'QueryResp'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

