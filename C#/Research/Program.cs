using System;
using Extensions;

namespace Research
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] input =
            {
                {1,2,3,2.5 },
                {2,5,-1,2 },
                {-1.5,2.7,3.3,-0.8 }
            };
            DenseLayer layer1 = new DenseLayer(4, 5);
            Console.WriteLine(layer1.biases.ToMatrixString());
            Console.WriteLine(layer1.weights.ToMatrixString());
        }
    }
}
