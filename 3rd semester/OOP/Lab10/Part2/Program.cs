using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
{
    class Program
    {
        static Random rnd = new Random();
        static void Main(string[] args)
        {
            int size = InsertVariables("Введите размер массива людей");
            Person[] peopleArray = null;
            CreatePersonsArray(size, ref peopleArray);
            ShowPersonsArray(peopleArray);
            
            Queries(peopleArray);
        }
        static void ShowMaleNames(Person[] peopleArray)
        {
            int counter = 0;
            foreach (var item in peopleArray)
            {
                if (item.Gender == "M")
                {
                    item.WriteFullNames();
                    counter++;
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Лиц мужского пола нет в списке!");
            }
        }
        static void ShowStudNamesOfChosenYear(Person[] peopleArray)
        {
            int yearToSearch = InsertVariables("Введите курс");
            int counter = 0;
            Student stud = new Student();
            foreach (var item in peopleArray)
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
        static void ShowAllFemaleCounter(Person[] peopleArray)
        {
            int femaleCounter = 0;
            foreach (var item in peopleArray)
            {
                if (item.Gender == "F")
                    femaleCounter++;
            }

            if (femaleCounter == 0)
                Console.WriteLine("Женщин в данном списке нет!");
            else
                Console.WriteLine("Количество женщин в списке - " + femaleCounter);
        }
        static void ShowStudOfChosenYearCount(Person[] peopleArray)
        {
            int yearToSearch = InsertVariables("Введите курс");
            int counter = 0;
            Student stud = new Student();
            foreach (var item in peopleArray)
            {
                if (item is Student)
                {
                    stud = item as Student;
                    if (stud.Year == yearToSearch)
                        counter++;

                }
                else if (item is PartTimeStudent)
                {
                    stud = item as PartTimeStudent;
                    if (stud.Year == yearToSearch)
                        counter++;
                }
            }

            if (counter == 0)
                Console.WriteLine("Студентов данного курса нет!");
            else
                Console.WriteLine("Количество студентов на данном курсе : " + counter);
        }
        static void ShowAllPupilNames(Person[] peopleArray)
        {
            int counter = 0;
            foreach (var item in peopleArray)
            {
                if (item is Schoolchild && !(item is Student) && !(item is PartTimeStudent))
                {
                    item.WriteFullNames();
                    counter++;
                }
            }

            if (counter == 0)
                Console.WriteLine("Школьников в списке нет!");
            else
                Console.WriteLine("Количество школьников в списке: " + counter);
        }
        static void Queries(Person[] peopleArray)
        {
            bool exit = false;
            do
            {
                Console.WriteLine("\n1. Имена всех лиц мужского пола.\n" 
                    + "2. Имена студентов указанного курса.\n"
                    + "3. Количество женщин.\n"
                    + "4. Количество студентов на указанном курсе.\n"
                    + "5. Имена всех школьников.\n"
                    + "6. Выход\n");
                switch (Console.ReadLine())
                {
                    case "1":
                        {
                            ShowMaleNames(peopleArray);
                            break;
                        }
                    case "2":
                        {
                            ShowStudNamesOfChosenYear(peopleArray);
                            break;
                        }
                    case "3":
                        {
                            ShowAllFemaleCounter(peopleArray);                            
                            break;
                        }
                    case "4":
                        {
                            ShowStudOfChosenYearCount(peopleArray);
                            break;
                        }
                    case "5":
                        {
                            ShowAllPupilNames(peopleArray);
                            break;
                        }
                    case "6":
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
        static void CreatePersonsArray(int size, ref Person[] peopleArray)
        {
            peopleArray = new Person[size];
            for (int i = 0; i < peopleArray.Length; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    peopleArray[i] = new Person();
                    peopleArray[i].RandomiseInfo();
                }
                else if (choice == 2)
                {
                    peopleArray[i] = new Schoolchild();
                    peopleArray[i].RandomiseInfo();
                }
                else if (choice == 3)
                {
                    peopleArray[i] = new Student();
                    peopleArray[i].RandomiseInfo();
                }
                else if (choice == 4)
                {
                    peopleArray[i] = new PartTimeStudent();
                    peopleArray[i].RandomiseInfo();
                }
            }
        }
        static void ShowPersonsArray(Person[] peopleArray)
        {
            foreach (var item in peopleArray)
            {
                item.Write();
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
