using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
{
    class Program
    {
        static Random rnd = new Random();
        static void Main(string[] args)
        {
            int size = 10;
            IExecutable[] arr = new IExecutable[size];
            CreatePersonsArray(size, ref arr);
            ShowPersonsArr(arr);
            
            Console.WriteLine("\nCортировка по фамилии\n");
            Array.Sort(arr);
            ShowPersonsArr(arr);           

            Console.WriteLine("\nCортировка по возрасту\n");
            Array.Sort(arr, new CompareByAge());
            ShowPersonsArr(arr);

            Search(arr);
            
            Console.WriteLine("\nГлубокое копирование");
            Person p = (Person)arr[0];
            Person deepClone = (Person)p.Clone();
            deepClone.Surname = "Clone " + deepClone.Surname;
            deepClone._id._number = 596;
            Console.WriteLine($"id: {deepClone._id._number}, {deepClone}");

            Console.WriteLine("\nПоверхностное копирование");
            Person p2 = (Person)arr[1];
            Person shallowClone = (Person)p2.ShallowClone();
            shallowClone.Surname = "Shallow clone " + shallowClone.Surname;
            shallowClone._id._number = 596;
            Console.WriteLine($"id: {shallowClone._id._number}, {shallowClone}\n");
            
            ShowPersonsArr(arr);
        }
        static void Search(IExecutable[] arr)
        {
            int ageToFind = InsertVariables("\nВведите возраст для поиска");
            int index = Array.BinarySearch(arr, new Person { Age = ageToFind }, new CompareByAge());
            if (index > -1 || index > arr.Length)
            {
                Console.WriteLine($"Найден! Номер элемента : {++index}");
                Console.WriteLine(arr[--index].ToString());
            }                
            else
                Console.WriteLine("Человек с данным возврастом не найден");
        }
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                    if (x > 0)
                        isParsed = true;
                    else
                        continue;
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }
        static void ShowPersonsArr(IExecutable[] arr)
        {
            foreach (var item in arr)
                Console.WriteLine(item.ToString());
        }
        static void CreatePersonsArray(int size, ref IExecutable[] peopleArray)
        {
            //peopleArray = new Person[size];
            for (int i = 0; i < peopleArray.Length; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    peopleArray[i] = p;
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    peopleArray[i] = s;
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    peopleArray[i] = s;
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    peopleArray[i] = s;
                }
            }
        }
    }    
}
