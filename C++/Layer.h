#include "Neuron.h"
#include "lib.h"

class Layer {
    public:
    NeuronListWithCorrespondingConnectionList connections;
    Layer(int number_of_inputs,int number_of_neurons) {
        int i=0,j=0;
        for(;i<number_of_neurons;i++) {
            Neuron neuron;
            ConnectionList tConnections;
            for(;j<number_of_inputs;j++) {
                Connection connection;
                tConnections.add(connection);
            }
            Layer::connections.add(&neuron,&tConnections);
        }
    };
    void forward(DoubleList input) {
        int i=0;
        for(;i<Layer::connections.size;i++) {
            Layer::connections.getKey(i)->forward(*Layer::connections.getValue(i),input);
        }
    };
    DoubleList getOutput() {
        DoubleList output;
        int i=0;
        for(;i<Layer::connections.size;i++) {
            output.add(Layer::connections.getKey(i)->output);
        }
        return output;
    };
};