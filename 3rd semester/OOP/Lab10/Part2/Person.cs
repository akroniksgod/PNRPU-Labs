using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
{
    public class Person
    {
        protected static Random rnd = new Random();
        protected string _surname, _name, _gender;
        protected int _age;
        public string Surname
        {
            get { return _surname; }
            set
            {
                string numbers = "1234567890";
                for (int i = 0; i < value.Length; i++)
                {
                    if (numbers.Contains(value[i]))
                        throw new FormatException();
                }
                _surname = value;
            }
        }
        public string Name
        {
            get { return _name; }
            set
            {
                string numbers = "1234567890";
                for (int i = 0; i < value.Length; i++)
                {
                    if (numbers.Contains(value[i]))
                        throw new FormatException();
                }
                _name = value;
            }
        }
        public int Age
        {
            get { return _age; }
            set { _age = value; }
        }
        public string Gender
        {
            get { return _gender; }
            set
            {
                if (value.Length == 1)
                    _gender = value;
                else
                    throw new ArgumentException();
            }
        }
        public Person()
        {
            _surname = "";
            _name = "";
            _age = 0;
            _gender = "";
        }
        public Person(string surname, string name, int age, string gen)
        {
            Surname = surname;
            Name = name;
            Age = age;
            Gender = gen;
        }
        public virtual void RandomiseInfo()
        {
            string[] maleNames = { "Александр", "Алексей", "Артур", "Бен", "Владимир", "Пётр", "Николай", "Максим" },
                femaleNames = { "Екатерина", "Анастасия", "Вероника", "Ева", "Ирина" },
                maleSurnames = { "Петров", "Иванов", "Алалуев", "Кукуев", "Занзибар", "Лоскутов", "Замарёв"},
                femaleSurnames = { "Замарёва", "Замбарёва", "Тедешка", "Петрова", "Стоматологова", "Пупкова" };

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
            Age = rnd.Next(20, 60);
        }
        public void WriteFullNames()
        {
            Console.WriteLine($"{Surname} {Name}");
        }
        public void Show()
        {
            Console.WriteLine($"Person: {Surname} {Name} {Age} лет");
        }
        public virtual void Write()
        {
            Console.WriteLine($"Person: {Surname} {Name} {Age} лет");
        }
    }
}
