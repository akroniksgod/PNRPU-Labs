using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
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
        public Schoolchild(int id, string surname, string name, int age, string gen, string schoolName, int year) : base(id, surname, name, age, gen)
        {
            SchoolName = schoolName;
            Year = year;
        }
        public override object RandomCreate()
        {
            Person personToReturn = (Person)base.RandomCreate();

            string[] schoolNames = { "№72", "№25", "№59", "№81", "№17", "№4" };

            return new Schoolchild(personToReturn._id._number, personToReturn.Surname, personToReturn.Name, personToReturn.Age,
                    personToReturn.Gender, schoolNames[rnd.Next(0, schoolNames.Length - 1)], rnd.Next(1, 12));
        }        
        public override string ToString()
        {
            return "id " + this._id._number.ToString() + " " + Surname + " " + Name + " " + Age.ToString() + " лет, " + SchoolName + ", класс " + Year.ToString();
        }
        public override void Write()
        {
            Console.WriteLine($"Schoolchild: {Surname} {Name} {Age} лет, {SchoolName}, класс {Year}");
        }
        public override object Clone()
        {
            return new Schoolchild(this._id._number, Surname, Name, Age, Gender, SchoolName, Year);
        }
        public override object ShallowClone()
        {
            return this.MemberwiseClone();
        }
        public static bool operator ==(Schoolchild obj1, Schoolchild obj2)
        {
            return (Person)obj1 == (Person)obj2 && obj1.SchoolName == obj2.SchoolName
                && obj1.Year == obj2.Year;// obj1._id._number == obj2._id._number && obj1.Surname == obj2.Surname && obj1.Name == obj2.Name && obj1.Age == obj2.Age;
        }
        public static bool operator !=(Schoolchild obj1, Schoolchild obj2)
        {
            return !(obj1 == obj2);
        }
        public override bool Equals(object obj)
        {
            if (obj is Schoolchild && !(obj is Student) && !(obj is PartTimeStudent))
            {
                Schoolchild p = (Schoolchild)obj;
                return this == p;
            }
            return false;
        }
    }
    
}
