using System;
using System.Collections.Generic;
using System.Linq;
using Lab12;
using PersonLibrary;

namespace Part2
{
    class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<IExecutable> tree = new BinaryTree<IExecutable>(5);
            tree.Show();

            var maleSet = BinaryTreeExtension.Where(tree, 
                (IExecutable x)=>((Person)x).Gender == "M");
            PrintInfo(maleSet);

            var femaleCount = tree.Count(delegate (IExecutable x)
            {
                return ((Person)x).Gender == "F";
            });
            Console.WriteLine($"Количество лиц женского пола составляет {femaleCount}");

            int sum = tree.Sum((x) => ((Person)x).Age);
            double average = tree.Average((x) => ((Person)x).Age);
            if (sum / (double)tree.Count == average)
                Console.WriteLine($"Средний возраст жителей {average}");

            Func<IExecutable, IExecutable, IExecutable> ageComparator = delegate (IExecutable p1, IExecutable p2)
            {
                if (((Person)p1).Age > ((Person)p2).Age)
                    return p1;
                return p2;
            };

            Person oldestPerson = (Person)tree.Max(ageComparator);
            Console.WriteLine($"Самый старший житель: {oldestPerson}");

            ageComparator = delegate (IExecutable p1, IExecutable p2)
            {
                if (((Person)p1).Age < ((Person)p2).Age)
                    return p1;
                return p2;
            };

            Person youngestPerson = (Person)tree.Min(ageComparator);//tree.Min((x) => ((Person)x).Age);
            Console.WriteLine($"Самый младший житель: {youngestPerson}");
        }
        private static void PrintInfo<T>(IEnumerable<T> collection)
        {
            if (collection.Count() > 0)
            {
                foreach (var item in collection)
                    Console.WriteLine(item);
                Console.WriteLine();
            }
            else
                Console.WriteLine("Нет подходящих элементов\n");
        }
    }
}