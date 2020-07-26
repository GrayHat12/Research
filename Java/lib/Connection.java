package lib;
import java.util.Random;

public class Connection {
    public double weight;
    public double value;
    public Connection() {
        this.weight = (new Random().nextDouble());
        this.weight *= ((new Random().nextInt(2)) == 0 ? -1 : 1);
        System.out.println("10 "+this.weight);
    }
    public void feed(double value) {
        this.value = value * this.weight;
    }
}