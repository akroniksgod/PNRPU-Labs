using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Part1;

namespace Part2
{
    class Program
    {
        static Random rnd = new Random();
        static void Main(string[] args)
        {
            SortedDictionary<int, IExecutable> myDict = new SortedDictionary<int, IExecutable>();
            bool exit = false;
            do
            {
                Console.WriteLine("1. Добавить элементы в коллекцию с помощью ДСЧ\n" + "2. Напечатать коллекцию\n"
                   + "3. Добавить элемент в коллекцию\n" + "4. Удалить элемент из коллекции\n"
                    + "5. Запросы\n" + "6. Выполнить поиск элемента\n" + "7. Клонирование\n" + "8. Выход из программы\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            FillMyDictWithRandom(ref myDict);
                            Console.WriteLine("Элементы добавлены\n");
                            break;
                        }
                    case "2":
                        {
                            if (myDict != null && myDict.Count != 0)
                                WriteDict(myDict);
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "3":
                        {
                            if (myDict != null)
                                AddToDict(ref myDict);
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "4":
                        {
                            if (myDict != null && myDict.Count != 0)
                                RemoveFromDict(ref myDict);
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "5":
                        {
                            if (myDict != null && myDict.Count != 0)
                                Queries(myDict);
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "6":
                        {
                            if (myDict != null && myDict.Count != 0)
                            {
                                SearchByAge(myDict);
                                Console.WriteLine();
                            }
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "7":
                        {
                            SortedDictionary<int, IExecutable> clone;                        
                            if (myDict != null && myDict.Count != 0)
                            {
                                clone = CopyCollection(myDict);
                                Console.WriteLine("Печать клона\n");
                                WriteDict(clone);
                            }
                            else
                                Console.WriteLine("Коллекция пуста!\n");
                            break;
                        }
                    case "8":
                        exit = true;
                        break;
                    default:
                        Console.WriteLine("Ошибка! Введите повторно");
                        break;
                }
            } while (!exit);
        }
        static SortedDictionary<int, IExecutable> CopyCollection(SortedDictionary<int, IExecutable> myDict)
        {
            SortedDictionary<int, IExecutable> tempDict = new SortedDictionary<int, IExecutable>();
            foreach (var item in myDict)
            {
                tempDict.Add(item.Key, item.Value);
            }            
            return tempDict;
        }
        static void SearchByAge(SortedDictionary<int, IExecutable> myDict)
        {
            int ageToFind = InsertVariables("\nВведите возраст для поиска"),
                counter = 0;
            foreach (var item in myDict)
            {
                if (((Person)item.Value).Age == ageToFind)
                {
                    Console.WriteLine("Найден\n" + item.Value.ToString());
                }
                else
                    counter++;
            }

            if (counter > 0)
            {
                Console.WriteLine("Не найден!");
            }
        }
        static void Queries(SortedDictionary<int, IExecutable> myDict)
        {
            bool exit = false;
            do
            {
                Console.WriteLine("\n1. Имена всех лиц женского пола.\n"
                    + "2. Имена учеников старшей школы.\n"
                    + "3. Количество мужчин.\n"
                    + "4. Количество студентов данного курса.\n"
                    + "5. Назад\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            ShowFemaleNames(myDict);
                            break;
                        }
                    case "2":
                        {
                            ShowHigherSchPupilNames(myDict);
                            break;
                        }
                    case "3":
                        {
                            ShowAllMaleCounter(myDict);
                            break;
                        }
                    case "4":
                        {
                            ShowStudCountOfChosenYear(myDict);
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
        static void ShowStudCountOfChosenYear(SortedDictionary<int, IExecutable> myDict)
        {
            int yearToSearch = InsertVariables("Введите курс");
            int counter = 0;

            Student stud = new Student();
            foreach (var item in myDict)
            {
                if (item.Value is Student)
                {
                    stud = item.Value as Student;
                    if (stud.Year == yearToSearch)
                    {
                        //stud.WriteFullNames();
                        counter++;
                    }
                }
            }

            if (counter == 0)
                Console.WriteLine("Студентов данного курса нет!\n");
            else
                Console.WriteLine($"Количество студентов данного курса: {counter}\n");
        }
        static void ShowHigherSchPupilNames(SortedDictionary<int, IExecutable> myDict)
        {
            int counter = 0;
            foreach (var item in myDict)
            {
                if (item.Value is Schoolchild)
                {
                    Schoolchild pupil = new Schoolchild();
                    pupil = item.Value as Schoolchild;
                    if (pupil.Year > 9)
                    {
                        Console.WriteLine(pupil.ToString());
                        counter++;
                    }
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Учеников страшей школы (10, 11 класс) нет в данном списке\n");
            }
        }
        static void ShowAllMaleCounter(SortedDictionary<int, IExecutable> myDict)
        {
            int maleCounter = 0;
            foreach (var item in myDict)
            {
                if (((Person)item.Value).Gender == "F")
                    maleCounter++;
            }

            if (maleCounter == 0)
                Console.WriteLine("Мужчин в данном списке нет!\n");
            else
                Console.WriteLine("Количество Мужчин в списке - " + maleCounter + "\n");
        }
        static void ShowFemaleNames(SortedDictionary<int, IExecutable> myDict)
        {
            int counter = 0;
            foreach (var item in myDict)
            {
                if (((Person)item.Value).Gender == "F")
                {
                    ((Person)item.Value).WriteFullNames();
                        counter++;
                }
            }

            if (counter == 0)            
                Console.WriteLine("Лиц женского пола нет в списке!\n");
            
        }
        static void RemoveFromDict(ref SortedDictionary<int, IExecutable> myDict)
        {            
            bool deletedElement = false;
            do
            {
                int elementToRemove = InsertVariables("Введите номер элемента, который необходимо удалить из очереди");
                if (myDict.ContainsKey(elementToRemove))
                {
                    myDict.Remove(elementToRemove);
                    deletedElement = true;
                }                   
                else
                    Console.WriteLine("Данного элемента нет!\n");
            } while (!deletedElement);
            Console.WriteLine("Элемент был удалён\n");
        }
        static void AddToDict(ref SortedDictionary<int, IExecutable> myDict)
        {
            Console.WriteLine("Выберете класс элемента:\n" + "1. Person\n"
                + "2. Schoolchild\n" + "3. Student\n" + "4. PartTimeStudent\n");
            switch (Console.ReadLine())
            {
                case "1":
                    {
                        Person p = new Person();
                        object toAdd = p.RandomCreate();
                        myDict.Add(myDict.Count + 1, (Person)toAdd);
                        Console.WriteLine(((Person)toAdd).ToString() + " добавлен\n");
                        break;
                    }
                case "2":
                    {
                        Schoolchild s = new Schoolchild();
                        object toAdd = s.RandomCreate();
                        myDict.Add(myDict.Count + 1, (Schoolchild)toAdd);
                        Console.WriteLine(((Schoolchild)toAdd).ToString() + " добавлен\n");
                        break;
                    }
                case "3":
                    {
                        Student s = new Student();
                        object toAdd = s.RandomCreate();
                        myDict.Add(myDict.Count + 1, (Student)toAdd);
                        Console.WriteLine(((Student)toAdd).ToString() + " добавлен\n");
                        break;
                    }
                case "4":
                    {
                        PartTimeStudent s = new PartTimeStudent();
                        object toAdd = s.RandomCreate();
                        myDict.Add(myDict.Count + 1, (PartTimeStudent)toAdd);
                        Console.WriteLine(((PartTimeStudent)toAdd).ToString() + " добавлен\n");
                        break;
                    }
                default:
                    Console.WriteLine("Ошибка!\n");
                    break;
            }
        }
        static void WriteDict(SortedDictionary<int, IExecutable> myDict)
        {
            Console.WriteLine();
            foreach (var item in myDict)
            {
                Console.WriteLine("Key: " + item.Key + ", Data: " + item.Value.ToString());
            }
            Console.WriteLine();
        }
        static void FillMyDictWithRandom(ref SortedDictionary<int, IExecutable> myDict)
        {
            int count = InsertVariables("Введите количество элементов для добавления");
            for (int i = 1, k = 0; i <= count; i++)
            {
                do
                {
                    k = rnd.Next(1, count + 999);
                } while (myDict.ContainsKey(k));

                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    myDict[k] = p;
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    myDict[k] = s;
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    myDict[k] = s;
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    myDict[k] = s;
                }
            }
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
