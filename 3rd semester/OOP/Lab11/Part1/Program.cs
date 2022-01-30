using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    class Program
    {
        static Random rnd = new Random();
        static void Main(string[] args)
        {
            bool exit = false, isSorted = false;
            Queue<IExecutable> myQueue = new Queue<IExecutable>();
            do
            {
                Console.WriteLine("1. Добавить элементы в коллекцию с помощью ДСЧ\n" + "2. Напечатать коллекцию\n"
                   + "3. Добавить элемент в коллекцию\n" + "4. Удалить элемент из коллекции\n" 
                    + "5. Запросы\n" + "6. Сортировка коллекции по возрасту\n" 
                    + "7. Выполнить поиск элемента\n" + "8. Клонирование\n" + "9. Выход из программы\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            FillQueueWithRandom(ref myQueue);
                            Console.WriteLine("Элементы добавлены\n");
                            break;
                        }
                    case "2":
                        {
                            if (myQueue != null && myQueue.Count != 0)
                                WriteQueue(myQueue);                       
                            else
                                Console.WriteLine("Очередь пуста!\n");
                            break;
                        }
                    case "3":
                        {
                            if (myQueue != null)
                                AddToQueue(ref myQueue);
                            else
                                Console.WriteLine("Очередь пуста!\n");
                            break;
                        }
                    case "4":
                        {
                            if (myQueue != null && myQueue.Count != 0)
                                RemoveFromQueue(ref myQueue);
                            else
                                Console.WriteLine("Очередь пуста!\n");
                            break;
                        }
                    case "5":
                        {
                            if (myQueue != null && myQueue.Count != 0)
                                Queries(myQueue);
                            else
                                Console.WriteLine("Очередь пуста!\n");                            
                            break;
                        }
                    case "6":
                        {
                            if (myQueue != null && myQueue.Count != 0)
                            { 
                                SortMyCollection(ref myQueue);
                                isSorted = true;
                                Console.WriteLine("Коллекция отсортированна!\n");
                            }
                            else
                                Console.WriteLine("Очередь пуста!\n");                            
                            break;
                        }
                    case "7":
                        {
                            if (myQueue != null && myQueue.Count != 0)
                            {
                                if (isSorted)
                                {
                                    SearchByAge(myQueue);
                                }
                                else
                                    Console.WriteLine("Необходимо отсортировать коллекцию!\n");                                
                            }
                            else
                                Console.WriteLine("Очередь пуста!\n");
                            break;
                        }
                    case "8":
                        {
                            Queue<IExecutable> clone = null;
                            if (myQueue != null && myQueue.Count != 0)
                            {
                                clone = CopyCollection(myQueue);
                                Console.WriteLine("Печать клона\n");
                                WriteQueue(clone);
                            }
                                
                            else
                                Console.WriteLine("Очередь пуста!\n");
                            break;
                        }
                    case "9":
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Ошибка! Введите повторно");
                        break;
                }
            } while (!exit);            
        }
        static Queue<IExecutable> CopyCollection(Queue<IExecutable> myQueue)
        {
            Queue<IExecutable> tempQueue = new Queue<IExecutable>();
            IExecutable[] tempArr = new IExecutable[myQueue.Count];
            myQueue.CopyTo(tempArr, 0);

            foreach (var item in tempArr)
            {
                tempQueue.Enqueue((Person)item.Clone());
            }
            return tempQueue;
        }
        static void SearchByAge(Queue<IExecutable> myQueue)
        {
            IExecutable[] personsArray = new IExecutable[myQueue.Count];
            int len = myQueue.Count;
            for (int i = 0; i < len; i++)
            {
                personsArray[i] = myQueue.Dequeue();
            }

            int ageToFind = InsertVariables("\nВведите возраст для поиска");
            int index = Array.BinarySearch(personsArray, new Person { Age = ageToFind }, new CompareByAge());
            if (index > -1 || index > personsArray.Length)
                Console.WriteLine($"Найден! Номер элемента : {++index}\n");
            else
                Console.WriteLine("Человек с данным возврастом не найден\n");
        }
        static void SortMyCollection(ref Queue<IExecutable> myQueue)
        {
            int len = myQueue.Count;
            IExecutable[] personsArray = new IExecutable[myQueue.Count];

            for (int i = 0; i < len; i++)
            {
                personsArray[i] = myQueue.Dequeue();
            }
            Array.Sort(personsArray, new CompareByAge());
            for (int i = 0; i < len; i++)
            {
                myQueue.Enqueue(personsArray[i]);
            }
        }
        static void Queries(Queue<IExecutable> myQueue)
        {
            bool exit = false;
            do
            {
                Console.WriteLine("\n1. Имена всех лиц мужского пола.\n"
                    + "2. Имена студентов указанного курса.\n"
                    + "3. Количество женщин.\n"                    
                    + "4. Имена всех школьников.\n"
                    + "5. Назад\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            ShowMaleNames(myQueue);
                            break;
                        }
                    case "2":
                        {
                            ShowStudNamesOfChosenYear(myQueue);
                            break;
                        }
                    case "3":
                        {
                            ShowAllFemaleCounter(myQueue);
                            break;
                        }
                    case "4":
                        {
                            ShowAllPupilNames(myQueue);
                            break;
                        }
                    case "5":
                        {
                            exit = true;
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода! Попробуйте выбрать заново");
                        break;
                }
            } while (!exit);
        }
        static void ShowAllPupilNames(Queue<IExecutable> myQueue)
        {
            int counter = 0;
            foreach (var item in myQueue)
            {
                if (item is Schoolchild && !(item is Student) && !(item is PartTimeStudent))
                {
                    Schoolchild s = item as Schoolchild;
                    s.WriteFullNames();
                    counter++;
                }
            }

            if (counter == 0)
                Console.WriteLine("Школьников в списке нет!");
            else
                Console.WriteLine("Количество школьников в списке: " + counter);
        }
        static void ShowAllFemaleCounter(Queue<IExecutable> myQueue)
        {
            int femaleCounter = 0;
            foreach (var item in myQueue)
            {
                if (((Person)item).Gender == "F")
                    femaleCounter++;
            }

            if (femaleCounter == 0)
                Console.WriteLine("Женщин в данном списке нет!");
            else
                Console.WriteLine("Количество женщин в списке - " + femaleCounter);
        }
        static void ShowStudNamesOfChosenYear(Queue<IExecutable> myQueue)
        {
            int yearToSearch = InsertVariables("Введите курс");
            int counter = 0;
            Student stud = new Student();
            foreach (var item in myQueue)
            {
                if (item is Student && !(item is PartTimeStudent))
                {
                    stud = item as Student;
                    if (stud.Year == yearToSearch)
                    {
                        stud.WriteFullNames();
                        counter++;
                    }
                }
                else if (item is PartTimeStudent)
                {
                    stud = item as PartTimeStudent;
                    if (stud.Year == yearToSearch)
                    {
                        stud.WriteFullNames();
                        counter++;
                    }
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Студентов данного курса нет!");
            }
        }
        static void ShowMaleNames(Queue<IExecutable> myQueue)
        {
            int counter = 0;
            foreach (var item in myQueue)
            {
                if (((Person)item).Gender == "M")
                {
                    ((Person)item).WriteFullNames();
                    counter++;
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Лиц мужского пола нет в списке!");
            }
        }
        static void RemoveFromQueue(ref Queue<IExecutable> myQueue)
        {
            int elementToRemove = InsertVariables("Введите номер элемента, который необходимо удалить из очереди"),
                elementsCount = myQueue.Count;
            Queue<IExecutable> tempQueue = new Queue<IExecutable>();
            for (int i = 0; i < --elementToRemove; i++)
            {
                tempQueue.Enqueue(myQueue.Dequeue());
            }
            myQueue.Dequeue();
            int length = myQueue.Count;
            for (int i = 0; i < length; i++)
            {
                tempQueue.Enqueue(myQueue.Dequeue());
            }
            elementsCount--;
            for (int i = 0; i < elementsCount; i++)
            {
                myQueue.Enqueue(tempQueue.Dequeue());
            }
            Console.WriteLine("Элемент удалён\n");
        }
        static void AddToQueue(ref Queue<IExecutable> myQueue)
        {
            Console.WriteLine("Выберете класс элемента:\n" + "1. Person\n"
                + "2. Schoolchild\n" + "3. Student\n" + "4. PartTimeStudent\n");
            switch (Console.ReadLine())
            {
                case "1":
                    {
                        Person p = new Person();
                        myQueue.Enqueue((Person)p.RandomCreate());
                        Console.WriteLine("Элемент добавлен\n");
                        break;
                    }                    
                case "2":
                    {
                        Schoolchild s = new Schoolchild();
                        myQueue.Enqueue((Schoolchild)s.RandomCreate());
                        Console.WriteLine("Элемент добавлен\n");
                        break;
                    }
                case "3":
                    {
                        Student s = new Student();
                        myQueue.Enqueue((Student)s.RandomCreate());
                        Console.WriteLine("Элемент добавлен\n");
                        break;
                    }
                case "4":
                    {
                        PartTimeStudent s = new PartTimeStudent();
                        myQueue.Enqueue((PartTimeStudent)s.RandomCreate());
                        Console.WriteLine("Элемент добавлен\n");
                        break;
                    }
                default:
                    Console.WriteLine("Ошибка!\n");
                    break;
            }
        }
        static void FillQueueWithRandom(ref Queue<IExecutable> myQueue)
        {
            int count = InsertVariables("Введите количество элементов для добавления");            
            for (int i = 0; i < count; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    myQueue.Enqueue(p);
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    myQueue.Enqueue(s);
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    myQueue.Enqueue(s);
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    myQueue.Enqueue(s);
                }
            }
        }
        static void WriteQueue(Queue<IExecutable> myQueue)
        {
            foreach (var item in myQueue)
            {
                Console.WriteLine(item.ToString());
            }
            Console.WriteLine();
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
    }
}
