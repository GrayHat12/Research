package lib;

import java.util.List;

public class Support {
    public static String listToString(List<Double> list) {
        String out = "[ ";
        for (double object : list) {
            out += object + " ,";
        }
        out = out.substring(0, out.length()-1);
        out += "]";
        return out;
    }
}