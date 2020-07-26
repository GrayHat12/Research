package lib;
import java.util.List;

public class Neuron {
    public double bias;
    public double output;
    public Neuron() {
        this.bias = 0d;
    }
    public void forward(List<Connection> connections,List<Double> values) {
        this.output = this.bias;
        if (connections.size() != values.size()) throw new Error("Shape Error Neuron forward");
        for(int i=0;i<connections.size();i++) {
            connections.get(i).feed(values.get(i));
            this.output += connections.get(i).value;
        }
    }
}