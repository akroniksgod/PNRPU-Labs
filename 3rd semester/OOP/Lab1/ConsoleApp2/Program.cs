using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
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
                Console.WriteLine("Введите число " + name);
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
        static void First(double x, double y)
        {                     
            bool res = !(Math.Abs(x) + Math.Abs(y) <= 5 && (x < 0 && y > 0)) && Math.Abs(x) + Math.Abs(y) <= 5;            
            Console.WriteLine($"\n{res} для точки ({x}, {y})\n");            
        }
        static void Main(string[] args)
        {            
            double x = InsertVariables("x");
            double y = InsertVariables("y");
            First(x, y);            
        }
    }
}
