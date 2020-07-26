import java.util.LinkedList;
import java.util.List;

import lib.Layer;
import lib.Support;

public class Driver {
    public static void main(String argsp[]) {
        List<Double> input = new LinkedList<>();
        input.add(1d);
        input.add(2d);
        input.add(3d);
        input.add(2.5d);
        Layer layer1 = new Layer(4, 2);
        Layer layer2 = new Layer(2, 4);
        layer1.forward(input);
        layer2.forward(layer1.getOutput());
        System.out.println(Support.listToString(layer1.getOutput()));
        System.out.println(Support.listToString(layer2.getOutput()));
    }
}