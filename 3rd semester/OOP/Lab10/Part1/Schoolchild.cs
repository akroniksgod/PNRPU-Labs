using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
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
        public Schoolchild(string surname, string name, int age, string schoolName, int year) : base(surname, name, age)
        {
            SchoolName = schoolName;
            Year = year;
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
