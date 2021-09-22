using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.ComTypes;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {    
        static double InsertVariables(string name)
        {
            double x;
            bool flag = true;
            string str;
            do
            {
                Console.WriteLine("Введите число "+ name);
                str = Console.ReadLine();
                if (double.TryParse(str, out x))                
                    flag = false;
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }                    
            } while (flag);

            return x;
        }
        static void Main(string[] args)
        {
            double n = InsertVariables("n");
            double m = InsertVariables("m");

            if (m == 1)
                Console.WriteLine("Нельзя вычислить!\n");
            else
            {
                First(n, m);
                Second(n, m);
                Third(n, m);
            }

            double x = InsertVariables("x");
            Fourth(x);   
        }
        static void First(double n, double m)
        {
            double r1 = n++ / --m;
            r1++;
            Console.WriteLine("1) (n++/--m)++ = " + r1 + "; n = " + n + "; m = " + m + ";\n");
        }

        static void Second(double n, double m)
        {
            bool r2 = ++m < n--;
            Console.WriteLine("2) ++m < n-- = " + r2 + "; n = " + n + "; m = " + m + ";\n");
        }

        static void Third(double n, double m)
        {
            bool r3 = --m > ++n;
            Console.WriteLine("3) --m > ++n = " + r3 + "; n = " + n + "; m = " + m + ";\n");
        }

        static void Fourth(double x)
        {
            x = Math.Pow(x, 2);
            double r4 = 7 * Math.Atan(x);
            Console.WriteLine("4) 7arctg(x^2) = " + r4 + "; x = " + x + ";\n");
        }
    }
}
