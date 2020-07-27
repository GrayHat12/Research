class Neuron {
    bias;
    output;
    constructor() {
        this.bias = 0;
    }
    forward(connections,values) {
        this.output = this.bias;
        if (connections.length != values.length) throw new Error("Shape Error Neuron forward");
        for(let i=0;i<connections.length;i++) {
            connections[i].feed(values[i]);
            this.output += connections[i].value;
        }
    }
}