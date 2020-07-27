#include "numpy.h"

class Connection {
    public : 
    double weight;
    double value;
    Connection* next;
    Connection() : weight(randn()), value(0.0), next(NULL){};
    void feed(double value) {
        Connection::value = value * Connection::weight;
    }
};