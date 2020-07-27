class Layer {
  constructor(number_of_inputs, number_of_neurons) {
    this.connections = new Map();
    for (let i = 0; i < number_of_neurons; i++) {
      let neuron = new Neuron();
      let tConnections = [];
      for (let j = 0; j < number_of_inputs; j++) {
        tConnections.push(new Connection());
      }
      this.connections.set(neuron, tConnections);
    }
  }
  forward(input) {
    this.connections.forEach((v, k) => {
      k.forward(v, input);
    });
  }
  getOutput() {
    let output = [];
    this.connections.forEach((v, k) => {
      output.push(k.output);
    });
    return output;
  }
}
