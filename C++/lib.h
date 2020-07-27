#include <stdlib.h>
#include "Connection.h"

class ConnectionList
{
    private:
    Connection* start;
    public:
    int size;
    ConnectionList():start(NULL),size(0) {};
    void add(Connection connection) {
        if (ConnectionList::start == NULL) {
            ConnectionList::start = &connection;
            ConnectionList::start->next = NULL;
            ConnectionList::size += 1;
            return;
        }
        Connection* tcon = ConnectionList::start;
        ConnectionList::size += 1;
        while (tcon->next!=NULL) {
            tcon = tcon->next;
        }
        tcon->next = &connection;
    };
    Connection* get(int index) {
        if(index>ConnectionList::size) return NULL;
        int i=0;
        Connection* tcon = ConnectionList::start;
        while(tcon!=NULL && i<=index) {
            tcon = tcon->next;
            i+=1;
        }
        if(i==index) return tcon;
        else return NULL;
    }
};

class Double {
    public:
    Double* next;
    double data;
    Double(): data(0),next(NULL) {};
    Double(double data): data(data),next(NULL) {};
};

class DoubleList {
    private:
    Double* start;
    public:
    int size;
    DoubleList():start(NULL),size(0) {};
    void add(double data) {
        if(DoubleList::start == NULL ){
            DoubleList::start = &Double(data);
            DoubleList::start->next = NULL;
            DoubleList::size += 1;
            return;
        }
        Double* tcon = DoubleList::start;
        DoubleList::size += 1;
        while (tcon->next!=NULL) {
            tcon = tcon->next;
        }
        tcon->next = new Double(data);
    };
    double get(int index) {
        if(index>DoubleList::size) return NULL;
        int i=0;
        Double* tcon = DoubleList::start;
        while(tcon!=NULL && i<=index) {
            tcon = tcon->next;
            i+=1;
        }
        if(i==index) return tcon->data;
        else return NULL;
    }
};

class ShapeError {};

class NeuronNode {
    public:
    Neuron* neuron;
    NeuronNode* next;
    NeuronNode():neuron(NULL),next(NULL) {};
};

class ConnectionListNode {
    public:
    ConnectionList* connectionList;
    ConnectionListNode* next;
    ConnectionListNode():connectionList(NULL),next(NULL) {};
};

class NeuronListWithCorrespondingConnectionList {
    public:
    NeuronNode* n_start;
    ConnectionListNode* c_start;
    int size;
    NeuronListWithCorrespondingConnectionList():n_start(NULL),c_start(NULL),size(0) {};
    void add(Neuron* key,ConnectionList* value) {
        if(NeuronListWithCorrespondingConnectionList::n_start == NULL && NeuronListWithCorrespondingConnectionList::c_start == NULL) {
            NeuronListWithCorrespondingConnectionList::n_start->neuron = key;
            NeuronListWithCorrespondingConnectionList::n_start->next = NULL;
            NeuronListWithCorrespondingConnectionList::c_start->connectionList = value;
            NeuronListWithCorrespondingConnectionList::c_start->next = NULL;
            NeuronListWithCorrespondingConnectionList::size += 1;
            return;
        }
        NeuronNode* tkey = NeuronListWithCorrespondingConnectionList::n_start;
        ConnectionListNode* tvalue = NeuronListWithCorrespondingConnectionList::c_start;
        while(tkey->next!=NULL) {
            tkey = tkey->next;
        }
        NeuronNode node;
        node.neuron = key;
        node.next = NULL;
        tkey->next = &node;
        while(tvalue!=NULL) {
            tvalue = tvalue->next;
        }
        ConnectionListNode cnode;
        cnode.connectionList = value;
        cnode.next = NULL;
        tvalue->next = &cnode;
        NeuronListWithCorrespondingConnectionList::size += 1;
    };
    Neuron* getKey(int index) {
        if(index>NeuronListWithCorrespondingConnectionList::size) return NULL;
        int i=0;
        NeuronNode* key = NeuronListWithCorrespondingConnectionList::n_start;
        while(key->next!=NULL && i<=index) {
            key = key->next;
            i+=1;
        }
        if(i==index) return key->neuron;
        else return NULL;
    }
    ConnectionList* getValue(int index) {
        if(index>NeuronListWithCorrespondingConnectionList::size) return NULL;
        int i=0;
        ConnectionListNode* value = NeuronListWithCorrespondingConnectionList::c_start;
        while(value->next!=NULL && i<=index) {
            value = value->next;
            i+=1;
        }
        if(i==index) return value->connectionList;
        else return NULL;
    }
};