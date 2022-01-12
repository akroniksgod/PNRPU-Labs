using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
{
    public class Schoolchild : Person
    {
        protected string _schoolName;
        protected int _year;
        public string SchoolName
        {
            get { return _schoolName; }
            set { _schoolName = value; }
        }
        public int Year
        {
            get { return _year; }
            set { _year = value; }
        }
        public Schoolchild() : base()
        {
            _schoolName = "";
            _year = 0;
        }
        public Schoolchild(string surname, string name, int age, string gen, string schoolName, int year) : base(surname, name, age, gen)
        {
            SchoolName = schoolName;
            Year = year;
        }
        public override void RandomiseInfo()
        {
            string[] maleNames = { "Александр", "Алексей", "Артур", "Бен", "Владимир", "Пётр", "Николай", "Максим" },
                femaleNames = { "Екатерина", "Анастасия", "Вероника", "Ева", "Ирина" },
                maleSurnames = { "Петров", "Иванов", "Алалуев", "Кукуев", "Занзибар", "Лоскутов", "Замарёв" },
                femaleSurnames = { "Замарёва", "Замбарёва", "Тедешка", "Петрова", "Стоматологова", "Пупкова" },
                schoolNames = { "№72", "№25", "№59", "№81", "№17", "№4" };

            int choice = rnd.Next(0, 2);
            if (choice == 0)
            {
                Name = maleNames[rnd.Next(0, maleNames.Length - 1)];
                Surname = maleSurnames[rnd.Next(0, maleSurnames.Length - 1)];
                Gender = "M";                
            }
            else
            {
                Name = femaleNames[rnd.Next(0, femaleNames.Length - 1)];
                Surname = femaleSurnames[rnd.Next(0, femaleSurnames.Length - 1)];
                Gender = "F";
            }
            Age = rnd.Next(7, 18);
            SchoolName = schoolNames[rnd.Next(0, schoolNames.Length - 1)];
            Year = rnd.Next(1, 12);
        }
        public new void Show()
        {
            Console.WriteLine($"Schoolchild: {Surname} {Name} {Age} лет, {SchoolName}, класс {Year}");
        }
        public override void Write()
        {
            Console.WriteLine($"Schoolchild: {Surname} {Name} {Age} лет, {SchoolName}, класс {Year}");
        }
    }
}
