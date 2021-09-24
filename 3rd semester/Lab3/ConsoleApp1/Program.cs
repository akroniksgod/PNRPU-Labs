using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        public const double EPS = 1e-4;
        static double F(double x)
        {
            return(Math.Exp(2 * x));
        }        
        static int Fact(int n)
        {
            int s = 1;
            for (int i = 1; i <= n; i++)
            {
                s *= i;
            }
            return s;
        }

        static void CountSN(ref double sn, double x)
        {
            sn = 1.0; 
            double chislitel = 1;
            int fact = 1;
            for (int n = 1; n <= 20; n++)
            {
                fact *= n;
                chislitel *= 2 * x;
                sn += chislitel / fact;
            }
        }

        static void CountSE(ref double se, double x)
        {
            se = 1;
            int fact = 1;
            double chislitel = 1, f = 0, prevF = 1;
            for (int i = 1; Math.Abs(prevF - f) > EPS; i++)
            {
                prevF = f;

                fact *= i;
                chislitel *= 2 * x;
                f = chislitel / fact;

                se += f;
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine("y = e^(2*x)\n");
            double a = 0.1, b = 1;
            double k = (b - a) / 10;

            int count = 0;
            for (double x = a; x < b; x += k, count++)
            {
                double sn = 0;
                CountSN(ref sn, x);

                double se = 0;
                CountSE(ref se, x);
                Console.WriteLine($"{count}) \tx = {x:0.0000}; \tSN = {sn:0.0000}; \tSE = {se: 0.0000}; \tY = {F(x):0.0000}\n");
            }
        }
    }
}
