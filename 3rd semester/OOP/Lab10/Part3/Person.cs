using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
{
    public class Person : IExecutable, IComparable, ICloneable
    {
        public Id _id { get; set; }
        protected static Random rnd = new Random();
        protected string _surname, _name, _gender;
        protected int _age;
        protected static int _counter;
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
        public int Counter
        {
            get { return _counter; }
        }
        public Person()
        {
            Id num = new Id(0);
            _id = num;
            _surname = "";
            _name = "";
            _age = 0;
            _gender = "";
            _counter++;
        }
        public Person(int id, string surname, string name, int age, string gen)
        {
            Id num = new Id(id);
            _id = num;            
            Surname = surname;
            Name = name;
            Age = age;
            Gender = gen;
            _counter++;
        }
        public virtual object RandomCreate()
        {
            Person personToReturn = new Person();
            string[] maleNames = { "Александр", "Алексей", "Артур", "Бен", "Владимир", "Пётр", "Николай", "Максим" },
                femaleNames = { "Екатерина", "Анастасия", "Вероника", "Ева", "Ирина", "София", "Елена" },
                maleSurnames = { "Петров", "Иванов", "Алалуев", "Кукуев", "Занзибар", "Лоскутов", "Замарёв" },
                femaleSurnames = { "Замарёва", "Замбарёва", "Яковлева", "Петрова", "Стоматологова", "Пупкова" };

            int choice = rnd.Next(0, 2);
            if (choice == 0)
            {
                Person tempPersonToReturn = new Person(rnd.Next(1, 10000), maleSurnames[rnd.Next(0, maleSurnames.Length - 1)], 
                    maleNames[rnd.Next(0, maleNames.Length - 1)], rnd.Next(20, 60), "M");
                personToReturn = tempPersonToReturn;
            }
            else
            {
                Person tempPersonToReturn = new Person(rnd.Next(1, 10000), femaleSurnames[rnd.Next(0, femaleSurnames.Length - 1)],
                    femaleNames[rnd.Next(0, femaleNames.Length - 1)], rnd.Next(20, 60), "F");
                personToReturn = tempPersonToReturn;
            }
            return personToReturn;
        }
        public override string ToString()
        {
            return "id " + this._id._number.ToString() + " " + Surname + " " + Name + " " + Age.ToString() + " лет";
        }
        public virtual int CompareTo(object obj)
        {
            return String.Compare(this.Surname, ((Person)obj).Surname);
        }
        public virtual object Clone()
        {
            return new Person(this._id._number, Surname, Name, Age, Gender);
        }
        public virtual object ShallowClone()
        {
            return this.MemberwiseClone();
        }
        public void WriteFullNames()
        {
            Console.WriteLine($"{Surname} {Name}");
        }
        public virtual void Write()
        {
            Console.WriteLine($"Person: {Surname} {Name} {Age} лет");
        }
        public static bool operator ==(Person obj1, Person obj2)
        {
            return obj1._id._number == obj2._id._number && obj1.Surname == obj2.Surname && obj1.Name == obj2.Name && obj1.Age == obj2.Age;
        }
        public static bool operator !=(Person obj1, Person obj2)
        {
            return !(obj1 == obj2);
        }
        public override bool Equals(object obj)
        {
            if (obj is Person && !(obj is Schoolchild) && !(obj is Student) && !(obj is PartTimeStudent))
            {
                Person p = (Person)obj;
                return (Person)this == p;
            }
            return false;
        }
    }
}
