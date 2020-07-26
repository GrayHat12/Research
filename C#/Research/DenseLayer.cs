using System;
using System.Collections.Generic;
using System.Text;

namespace Research
{
    class DenseLayer
    {
        public double[,] weights;
        public double[,] biases;
        public double[,] output;
        public DenseLayer(int n_inputs,int n_neurons)
        {
            this.weights = Numpy.randn(n_inputs, n_neurons);
            this.biases = Numpy.zeros(1, n_neurons);
        }

        public void forward(double[,] inputs)
        {
            this.output = Numpy.sum(Numpy.dot(inputs, this.weights),this.biases);
        }
    }
}
