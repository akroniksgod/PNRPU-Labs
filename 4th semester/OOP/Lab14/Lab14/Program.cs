using System;
using System.Collections.Generic;
using System.Linq;
using PersonLibrary;

namespace Lab14
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int cap = 5;
            City city = new City(cap - 2);
            EducationaLInstitution institution = new EducationaLInstitution(cap);
            city._institutions.Peek()._people.Add(city._institutions.Count, new Person(15, "ted", "de", 23, "M"));
            city.Show();

            FemaleNamesQuery(city);
            MaleCountQuery(city);
            AverageAgeInCityQuery(city);
            ExactYearStudentNamesQuery(city);
            OrderedFemaleStudentNamesQuery(city);
            SubstrCollectionsQuery(city);
            GroupedByAgeStudentsQuery(city);
        }
        private static void GroupedByAgeStudentsQuery(City city)
        {
            Intro("\nЗапрос на группировку учащихся в учебном заведении по полу\n");
            //var list = from student in city._people.Values
            //           group student by student.Gender into pers 
            //           select new 
            //           { 
            //               Gender = pers.Key,
            //               Count = pers.Count(), 
            //               People = from p in pers select p 
            //           };

            
            var list = from iterator in city._institutions
                       from person in iterator._people.Values
                       group person by person.Gender into tempPerson
                       select new
                       {
                           Gender = tempPerson.Key,
                           Count = tempPerson.Count(),
                           People = from p in tempPerson select p
                       };

            foreach (var persons in list)
            {
                Console.WriteLine($"{persons.Gender} : {persons.Count}");
                foreach (var person in persons.People)
                {
                    Console.WriteLine(person);
                }
                Console.WriteLine();
            }
        }
        
        //Операция над множествами
        private static void SubstrCollectionsQuery(City city)
        {
            Intro("\nЗапрос на отображение городских жителей за исключением школьников и студентов\n");

            //var list = (from person in institution._people.Values select person).Except(from person in institution._people.Values where person is Schoolchild select person);

            var list = (from iterator in city._institutions
                        from person in iterator._people.Values
                        select person).Except(from iterator in city._institutions
                                              from pupil in iterator._people.Values
                                              where pupil is Schoolchild
                                              select pupil);
            PrintInfo(list);
        }

        //Запрос на выборку
        private static void OrderedFemaleStudentNamesQuery(City city)
        {
            //Linq + лямбда
            Intro("\nЗапрос на отсортированный по алфавиту список студентов и школьников женского пола");

            Func<Schoolchild, bool> comparator = (st) => (st.Gender == "F");

            var femaleList = from iterator in city._institutions
                             from person in iterator._people.Values
                             where person is Schoolchild && comparator((Schoolchild)person)
                             orderby person.Surname
                             select person;

            //var femaleList = from female in city._people.Values
            //                 where female is Schoolchild && comparator((Schoolchild)female)
            //                 orderby female.Surname
            //                 select female;

            PrintInfo(femaleList);
        }

        //Агрегирование данных
        private static void AverageAgeInCityQuery(City city)
        {
            //Агрегация с лямбдой, расширяющими методами
            Func <Person, int> f = delegate (Person p) { return p.Age; };

            var humans = city._institutions.SelectMany(x => x._people.Values).ToArray();
            var intArr = humans.Select(f);
            var humanCount = humans.Count();
            
            int sum = intArr.Aggregate<int>((a, b) => a + b);
            Intro("Средний возраст в городе = " + Math.Round((double)sum / humanCount));
        }

        //Запрос на счётчик
        private static void MaleCountQuery(City city)
        {
            //Linq запрос c лямбдой
            var counter = (city._institutions.SelectMany(x => x._people.Values).Where(person => person.Gender == "M")).Count();
            /*var count = (from male in city.persons
                         where male.Gender == "M" select male).Count();*/

            Intro($"Количество мужчин в городе = {counter}");
        }

        //Запрос на выборку
        private static void FemaleNamesQuery(City city)
        {
            //Использование метода расширения
            Intro("\nСписок лиц женского пола в городе");
            
            Func<Person, bool> predicateFunc = delegate (Person p)
            {
                return p.Gender == "F";
            };

            var femaleSet = (city._institutions.SelectMany(x => x._people.Values)).Where(predicateFunc);
            PrintInfo(femaleSet);
        }

        //Запрос на выборку
        private static void ExactYearStudentNamesQuery(City city)
        {
            //Linq запрос
            Intro("Студенты выбранного курса\n");

            int year = InsertVariables("Введите номер курса для студентов");
            //var studentNames = from person in institution._people.Values 
            //                        where person is Student && ((Student)person).Year == year select person.ToString();

            var studentNames = from iterator in city._institutions
                                    from el in iterator._people.Values
                                            where el is Student && ((Student)el).Year == year
                                            select el.ToString();
            
            PrintInfo(studentNames);           
        }
        public static int InsertVariables(string toAsk)
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
                }
            } while (!isParsed);

            return x;
        }
        private static void Intro(string text)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(text);
            Console.ResetColor();
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