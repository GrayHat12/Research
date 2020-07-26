package lib;
import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.List;

public class Layer {
    public Map<Neuron,List<Connection>> connections = new HashMap<>();

    public Layer(int number_of_inputs,int number_of_neurons) {
        for (int i=0;i<number_of_neurons;i++) {
            Neuron neuron = new Neuron();
            List<Connection> tConnections = new LinkedList<>();
            for(int j=0;j<number_of_inputs;j++) {
                tConnections.add(new Connection());
            }
            this.connections.put(neuron, tConnections);
        }
    }
    public void forward(List<Double> input) {
        for (Map.Entry<Neuron,List<Connection>> entry: this.connections.entrySet()) {
            entry.getKey().forward(entry.getValue(), input);
        }
    }
    public List<Double> getOutput() {
        List<Double> output = new LinkedList<>();
        for (Map.Entry<Neuron,List<Connection>> entry : this.connections.entrySet()) {
            output.add(entry.getKey().output);
        }
        return output;
    }
}