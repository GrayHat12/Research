using System;
using System.Collections.Generic;
using System.Text;

namespace Research
{
    static class Numpy
    {
        public static double[,] randn(int rows,int cols)
        {
            double[,] output = new double[rows,cols];
            Random rand = new Random();
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    double val = rand.NextDouble();
                    val -= 0.5;
                    val *= 2;
                    output[i, j] = val;
                }
            }
            return output;
        }
        public static double[,] zeros(int rows, int cols)
        {
            double[,] output = new double[rows, cols];
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    output[i, j] = 0;
                }
            }
            return output;
        }
        public static double[,] dot(double[,] mata,double[,] matb)
        {
            if (mata.GetLength(1) != matb.GetLength(0)) throw new InvalidOperationException("shape error");
            int m = mata.GetLength(0), n = mata.GetLength(1), o = matb.GetLength(1);
            double[,] output = new double[m, o];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<o;j++)
                {
                    output[i, j] = 0;
                    for(int k=0;k<n;k++)
                    {
                        output[i, j] = output[i, j] + (mata[i, k] * matb[k, j]);
                    }
                }
            }
            return output;
        }
        public static double[,] sum(double[,] a, double[] b)
        {
            if (a.GetLength(0) != b.Length) throw new InvalidOperationException("shape error");
            for(int i=0;i<a.GetLength(0);i++)
            {
                for(int j=0;j<a.GetLength(1);j++)
                {
                    a[i, j] += b[i];
                }
            }
            return a;
        }
        public static double[,] sum(double[,] a, double[,] b)
        {
            if (b.GetLength(0) == 1)
            {
                for (int i = 0; i < a.GetLength(0); i++)
                {
                    for (int j = 0; j < a.GetLength(1); j++)
                    {
                        a[i, j] += b[0, i];
                    }
                }
                return a;
            }
            if (a.GetLength(0) != b.GetLength(0) || a.GetLength(1) != b.GetLength(1)) throw new InvalidOperationException("shape error");
            for (int i = 0; i < a.GetLength(0); i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                {
                    a[i, j] += b[i,j];
                }
            }
            return a;
        }
        public static double[,] sum(double[,] a, double b)
        {
            for (int i = 0; i < a.GetLength(0); i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                {
                    a[i, j] += b;
                }
            }
            return a;
        }
        public static double[] sum(double[] a, double b)
        {
            for (int i = 0; i < a.GetLength(0); i++)
            {
                a[i] += b;
            }
            return a;
        }
        public static double[] sum(double[] a, double[] b)
        {
            if (a.GetLength(0) != b.Length) throw new InvalidOperationException("shape error");
            for (int i = 0; i < a.GetLength(0); i++)
            {
                a[i] += b[i];
            }
            return a;
        }
    }
}
