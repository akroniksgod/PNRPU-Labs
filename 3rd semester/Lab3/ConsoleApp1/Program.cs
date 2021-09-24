using System;
using System.Collections.Generic;
using System.Linq;
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
        static void Main(string[] args)
        {
            Console.WriteLine("y = e^(2*x)\n");
            double a = 0.1, b = 1;
            double k = (b - a) / 10;

            int count = 0;
            for (double x = a; x <= b; x += k, count++)
            {
                Console.WriteLine($"{count}\nx = {x}");
                double s = 1.0;
                for (int n = 1; n <= 20; n++)
                {
                    if (n == 1)
                        s += Math.Pow(x * 2, n);
                    else
                        s += Math.Pow(x * 2, n) / (n * (n - 1));
                }
                Console.WriteLine($"SN = {s}");

                double se = 1, f = 0, prevF = 1;
                for (int i = 1; Math.Abs(prevF - f) > EPS; i++)
                {
                    prevF = f;
                    if (i == 1)
                        f = Math.Pow(x * 2, i);
                    else
                        f = Math.Pow(x * 2, i) / (i * (i - 1));
                    se += f;
                }
                Console.WriteLine($"SE = {se}\nY = {F(x)}\n");
            }
        }
    }
}
