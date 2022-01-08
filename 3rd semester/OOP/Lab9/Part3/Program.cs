using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Диапазоны сгенерированные с помощью ДСЧ");
            DiapasonArray diapasons1 = new DiapasonArray(5);
            diapasons1.Write();

            Console.WriteLine("\nДиапазоны вводимые пользователем");
            int count = InsertVariables("Введите количество диапазонов");
            DiapasonArray diapasons2 = new DiapasonArray(count, 0);
            diapasons2.Write();

            Console.WriteLine($"Количество экземпляров класса DiapasonArray: { diapasons2.Count }");
            
            Console.WriteLine("Максимальное значение в массиве диапазонов 1");

            Diapason max = diapasons1[0];
            for (int i = 1; i < diapasons1.Size; i++)
            {
                if (!max < !diapasons1[i])
                    max = diapasons1[i];
            }
            max.Show();
        }
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x) & x > 0)
                    isParsed = true;
                else
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
            } while (!isParsed);

            return x;
        }
    }
}
