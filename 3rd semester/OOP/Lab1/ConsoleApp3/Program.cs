using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 1000, b = 0.0001, r1, r2, r3, r4;
            r1 = Math.Pow(a + b, 2);
            r2 = Math.Pow(a, 2) + 2 * a * b;
            r3 = Math.Pow(b, 2);
            r4 = (r1 - r2) / r3;
            Console.WriteLine("Тип double, результат = " + r4);

            float a1 = (float)Math.Pow(a + b, 2);
            float a2 = (float)Math.Pow(a, 2) + 2 * (float)a * (float)b;
            float a3 = (float)Math.Pow(b, 2);
            float a4 = (a1 - a2) / a3;
            Console.WriteLine($"Тип float, результат = {a4}");
        }
    }
}
