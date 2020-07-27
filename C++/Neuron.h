#include "lib.h"

class Neuron {
    public:
    double bias;
    double output;
    Neuron(): bias(0.0),output(0.0){};
    void forward(ConnectionList connections,DoubleList values){
        Neuron::output = Neuron::bias;
        int i;
        if(connections.size != values.size) throw ShapeError();
        for(int i=0;i<connections.size;i++) {
            connections.get(i)->feed(values.get(i));
            Neuron::output += connections.get(i)->value;
        }
    }
};