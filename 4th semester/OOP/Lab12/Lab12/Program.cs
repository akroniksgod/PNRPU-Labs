using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PersonLibrary;

namespace Lab12
{
    class Program
    {
        static Random rnd = new Random();
        static void Main(string[] args)
        {
            BinaryTree<IExecutable> tree = null, treeClone = null;
            bool exit = false;
            do
            {
                Console.WriteLine("1. Создать дерево\n"
                    + "2. Напечатать дерево\n"
                    + "3. Удалить элемент по значению\n"
                    + "4. Добавить элементы\n"
                    + "5. Глубокое копирование\n"
                    + "6. Поверхностное копирование\n"
                    + "7. Очистка памяти\n"
                    + "8. Выход");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            DeclareTree(ref tree);
                            Console.WriteLine("Дерево создано\n");
                            break;
                        }
                    case "2":
                        {
                            if (tree != null && tree.Count != 0)
                                WriteTree(tree);
                            else
                                Console.WriteLine("Дерево не содержит элементов\n");
                            break;
                        }
                    case "3":
                        {
                            if (tree != null && tree.Count != 0)
                                DeleteElementsFrom(ref tree);
                            else
                                Console.WriteLine("Дерево пустое\n");
                            break;
                        }
                    case "4":
                        {                            
                            if (tree != null)
                                AdditionFunc(ref tree);
                            else
                                Console.WriteLine("Дерево не объявлено\n");
                            break;
                        }
                    case "5":
                        {
                            if (tree != null && tree.Count != 0)
                            {
                                treeClone = tree.Clone();
                                Person root = treeClone.Root._value as Person;

                                if (root != null)
                                {
                                    root.Name = "CloneName";
                                    WriteTree(treeClone);
                                }
                                Console.WriteLine("Глубокое копирование выполнено\n");
                            }
                            else
                                Console.WriteLine("Дерево не содержит элементов\n");
                            break;
                        }
                    case "6":
                        {
                            if (tree != null && tree.Count != 0)
                            {
                                treeClone = tree.ShallowCopy();
                                Person root = treeClone.Root._value as Person;

                                if (root != null)
                                {
                                    root.Name = "ShallowCopyName";
                                    WriteTree(treeClone);
                                }
                                Console.WriteLine("Поверхностное копирование выполнено\n");
                            }
                            else
                                Console.WriteLine("Дерево не содержит элементов\n");
                            break;
                        }
                    case "7":
                        {
                            if (tree != null && tree.Count != 0)
                            {
                                tree.Clear();
                                Console.WriteLine("Очистка выполнена\n");
                            }
                            else
                                Console.WriteLine("Дерево не содержит элементов\n");
                            break;
                        }
                    case "8": exit = true; break;
                    default: Console.WriteLine("Ошибка ввода\n"); break;
                }
            } while (!exit);
        }
        static void DeclareTree(ref BinaryTree<IExecutable> tree)
        {
            BinaryTree<IExecutable> randTree = new BinaryTree<IExecutable>();
            bool exit = false;
            Console.WriteLine();
            do
            {
                Console.WriteLine("Выбрать конструктор:\n"
                    + "1. Пустой - MyCollection()\n"
                    + "2. С параметром capacity - MyCollection(int capacity)\n"
                    + "3. С параметром MyCollection<T> - MyCollection<T>(MyCollection<T> collection)");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            tree = new BinaryTree<IExecutable>();
                            exit = true;
                            break;
                        }
                    case "2":
                        {
                            int capacity = InsertVariables("Какой размер?");
                            tree = new BinaryTree<IExecutable>(capacity);
                            exit = true;
                            break;
                        }
                    case "3":
                        {
                            FillTreeWithRandom(ref randTree);
                            tree = new BinaryTree<IExecutable>(randTree);
                            exit = true;
                            break;
                        }
                    default:
                        Console.WriteLine("Ошибка ввода\n");
                        break;
                }
            } while (!exit);
        }
        static void FillTreeWithRandom(ref BinaryTree<IExecutable> myTree)
        {
            int count = InsertVariables("Введите количество элементов для добавления");
            for (int i = 0; i < count; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    myTree.Add(p);
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    myTree.Add(s);
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    myTree.Add(s);
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    myTree.Add(s);
                }
            }
            Console.WriteLine("Элементы добавлены");
        }
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                {
                    if (x > 0)
                        isParsed = true;
                    else
                        continue;
                }                    
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }
        static void WriteTree(BinaryTree<IExecutable> tree)
        {
            foreach (var item in tree)
            {
                if (item != null)
                    Console.WriteLine(item.ToString());
                else
                    Console.WriteLine("null");
            }
            Console.WriteLine();
            //tree.Show();
        }
        static void DeleteElementsFrom(ref BinaryTree<IExecutable> tree)
        {
            IExecutable elemToDelete = null;
            switch (DefineClass())
            {
                case 1: elemToDelete = CreateElemToRemove(); break;
                case 2: elemToDelete = CreateElemToRemove(0); break;
                case 3: elemToDelete = CreateElemToRemove((float)1.0); break;
                case 4: elemToDelete = CreateElemToRemove(1.0); break;
                default: Console.WriteLine("Ошибка ввода\n"); break;
            }
            
            if (tree.Find(elemToDelete))
                tree.Remove(elemToDelete);
        }
        static int DefineClass()
        {
            bool exit = false;
            int decision = 0;
            do
            {
                Console.WriteLine("Какой класс для объекта?\n"
                                + "1. Персона\n"
                                + "2. Школьник\n"
                                + "3. Студент\n"
                                + "4. Студент-заочник");
                decision = InsertVariables("");
                if (decision < 5 && decision > 0)
                    exit = true;
            } while (!exit);
            return decision;
        }
        static void AdditionFunc(ref BinaryTree<IExecutable> tree)
        {
            bool exit = false;
            do
            {
                Console.WriteLine("1. Заполнение через ДСЧ\n"
                    + "2. Заполнение вручную\n");
                switch (Console.ReadLine())
                {
                    case "1": FillTreeWithRandom(ref tree); exit = true; break;
                    case "2": AddElementsTo(ref tree); exit = true; break;
                    default: Console.WriteLine("Ошибка ввода"); break;
                }
            } while (!exit);
        }
        static Person CreateElemToRemove()
        {
            int id = InsertVariables("Id?");
            Console.WriteLine("Фамилия?");
            string surname = Console.ReadLine();
            Console.WriteLine("Имя?");
            string name = Console.ReadLine();
            int age = InsertVariables("Возраст?");
            Console.WriteLine("Пол? (M/F)");
            string gender = Console.ReadLine();
            return new Person(id, surname, name, age, gender);
        }
        static Schoolchild CreateElemToRemove(int param)
        {
            int id = InsertVariables("Id?");
            Console.WriteLine("Фамилия?");
            string surname = Console.ReadLine();
            Console.WriteLine("Имя?");
            string name = Console.ReadLine();
            int age = InsertVariables("Возраст?");
            Console.WriteLine("Пол? (M/F)");
            string gender = Console.ReadLine();
            Console.WriteLine("Название школы?");
            string schoolName = Console.ReadLine();
            int year = InsertVariables("Номер класса?");
            return new Schoolchild(id, surname, name, age, gender, schoolName, year);
        }
        static Student CreateElemToRemove(float param)
        {
            int id = InsertVariables("Id?");
            Console.WriteLine("Фамилия?");
            string surname = Console.ReadLine();
            Console.WriteLine("Имя?");
            string name = Console.ReadLine();
            int age = InsertVariables("Возраст?");
            Console.WriteLine("Пол? (M/F)");
            string gender = Console.ReadLine();
            Console.WriteLine("Название школы?");
            string schoolName = Console.ReadLine();
            int year = InsertVariables("Номер класса?");
            Console.WriteLine("Название группы?");
            string groupName = Console.ReadLine();
            Console.WriteLine("Название направления?");
            string major = Console.ReadLine();
            return new Student(id, surname, name, age, gender, schoolName, year,groupName, major);
        }
        static PartTimeStudent CreateElemToRemove(double param)
        {
            int id = InsertVariables("Id?");
            Console.WriteLine("Фамилия?");
            string surname = Console.ReadLine();
            Console.WriteLine("Имя?");
            string name = Console.ReadLine();
            int age = InsertVariables("Возраст?");
            Console.WriteLine("Пол? (M/F)");
            string gender = Console.ReadLine();
            Console.WriteLine("Название школы?");
            string schoolName = Console.ReadLine();
            int year = InsertVariables("Номер класса?");
            Console.WriteLine("Название группы?");
            string groupName = Console.ReadLine();
            Console.WriteLine("Название направления?");
            string major = Console.ReadLine();
            long cardNumber = InsertVariables("Номер трудовой книжки");
            return new PartTimeStudent(id, surname, name, age, gender, schoolName, year, groupName, major, cardNumber);
        }
        static void AddElementsTo(ref BinaryTree<IExecutable> tree)
        {
            IExecutable elemToAdd = null;
            switch (DefineClass())
            {
                case 1: elemToAdd = CreateElemToRemove(); break;
                case 2: elemToAdd = CreateElemToRemove(0); break;
                case 3: elemToAdd = CreateElemToRemove((float)1.0); break;
                case 4: elemToAdd = CreateElemToRemove(1.0); break;
                default: Console.WriteLine("Ошибка ввода\n"); break;
            }
            tree.Add(elemToAdd);
            Console.WriteLine("Элемент добавлен\n");
        }
    }
}