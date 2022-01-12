using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    public class Person
    {
        protected string _surname, _name;
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
        public Person()
        {
            _surname = "";
            _name = "";
            _age = 0;
        }
        public Person(string surname, string name, int age)
        {
            Surname = surname;
            Name = name;
            Age = age;
        }
        public void Show()
        {
            Console.WriteLine($"Person: {Surname} {Name} {Age} лет");
        }
        public virtual void Write()
        {
            Console.WriteLine($"Person: {Surname} {Name} {Age} лет");
        }
        public static bool operator ==(Person obj1, Person obj2)
        {
            return obj1.Surname == obj2.Surname && obj1.Name == obj2.Name && obj1.Age == obj2.Age;
        }
        public static bool operator !=(Person obj1, Person obj2)
        {
            return !(obj1 == obj2);
        }
    }
}
