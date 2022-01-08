using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
{
    public class DiapasonArray
    {
        static Random rnd = new Random();

        Diapason[] arr;
        int _size;
        static int counter = 0;
        public int Count
        { 
            get { return counter; }
        }
        public Diapason this[int index]
        {
            get 
            {
                if (index >= 0 && index < arr.Length)
                    return arr[index];
                else
                    throw new IndexOutOfRangeException();
            }
            set 
            {
                if (index >= 0 && index < arr.Length)
                    arr[index] = value;
                else
                    throw new IndexOutOfRangeException();
            }
        }
        public int Size
        {
            get { return _size; }
        }
        public DiapasonArray()
        {
            arr = null;
            counter++;
        }
        public DiapasonArray(int size)
        {
            _size = size;
            arr = new Diapason[size];
            for (int i = 0; i < size; i++)
            {
                int value = rnd.Next(-50, 50), val2 = rnd.Next(25, 100);                
                arr[i] = new Diapason(value, value + val2);
            }
            counter++;
        }
        public DiapasonArray(int size, int h)
        {
            _size = size;
            arr = new Diapason[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = new Diapason();
                InputDiapason(ref arr[i]);
            }
            counter++;
        }
        public void Write()
        {
            int count = 1;
            foreach (Diapason item in arr)
            {
                Console.WriteLine($"{count}) {item.Write()}");
                count++;
            }
        }
        public static bool operator ==(DiapasonArray diapason1, DiapasonArray diapason2)
        {
            return diapason1.Size == diapason2.Size;
        }
        public static bool operator !=(DiapasonArray diapason1, DiapasonArray diapason2)
        {
            return !(diapason1 == diapason2);
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
