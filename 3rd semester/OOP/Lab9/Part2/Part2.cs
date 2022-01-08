using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
{
    class Part2
    {
        static void Main(string[] args)
        {
            Diapason diapason1 = new Diapason();
            InputDiapason(ref diapason1);            
            
            Console.WriteLine($"Длина диапазона: {!diapason1}");

            int flooredX = diapason1;
            Console.WriteLine($"Неявное преобразование типа: {flooredX}");

            Console.WriteLine($"Явное преобразование типа: {(double)diapason1}");

            ShowMinusOverloading(diapason1);

            Console.WriteLine("Введите второй диапазон");
            Diapason diapason2 = new Diapason();
            InputDiapason(ref diapason2);
            Console.WriteLine($"Диапазон 1 пересекает диапазон 2: {diapason1 < diapason2}");
        }
        static void ShowMinusOverloading(Diapason diapason1)
        {
            bool correctSubstaction = false;
            do
            {
                double toSubtract = InsertVariables("\nВведите число, которое нужно отнять");
                try
                {
                    Diapason check2 = toSubtract - diapason1;
                    Console.WriteLine($"Перегрука опеатора -: {check2.Write()}");

                    Diapason check = diapason1 - toSubtract;
                    Console.WriteLine($"Перегрука опеатора -: {check.Write()}");
                    correctSubstaction = true;
                }
                catch (ArithmeticException)
                {
                    Console.WriteLine("Ошибка");
                }
            } while (!correctSubstaction);
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
        static double InsertVariables(string toAsk)
        {
            double x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (double.TryParse(Console.ReadLine(), out x))
                    isParsed = true;
                else
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
            } while (!isParsed);

            return x;
        }
    }
}
