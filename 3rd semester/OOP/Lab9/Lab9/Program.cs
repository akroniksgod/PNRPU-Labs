using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9
{
    class Program
    {        
        static void Main(string[] args)
        {
            Diapason diapason1 = new Diapason();
            InputDiapason(ref diapason1);
            Diapason diapason2 = new Diapason();
            InputDiapason(ref diapason2);

            Console.WriteLine("Диапазон 1 пересекает диапазон 2 (метод класса) - " + diapason1.Intersect(diapason2));
            Console.WriteLine("То же самое через статическую функцию - " + Diapason.Intersects(diapason1, diapason2));
            Console.WriteLine("Количество объектов класса Diapason - " + diapason1.Count);
            
            Console.WriteLine("1-й диапазон");
            diapason1.Show();
            Console.WriteLine("2-й диапазон");
            diapason2.Show();
        }
        static void InputDiapason(ref Diapason diapason)
        {
            double begin, end;
            begin = InsertVariables("Введите значение х");
            diapason.X = begin;
            bool caughtError = false;
            do
            {
                end = InsertVariables("Введите значение y");
                try
                {                    
                    diapason.Y = end;
                    caughtError = true;
                }
                catch (ArithmeticException)
                {
                    Console.WriteLine("Ошибка!");
                }
            } while (!caughtError);
        }
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                    isParsed = true;
                else
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
            } while (!isParsed);

            return x;
        }
    }
}
