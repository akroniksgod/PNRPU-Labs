using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    public class Student : Schoolchild
    {
        protected string _groupName, _majorName;
        public string GroupName
        {
            get { return _groupName; }
            set { _groupName = value; }
        }
        public string MajorName
        {
            get { return _majorName; }
            set
            {
                string numbers = "1234567890";
                for (int i = 0; i < value.Length; i++)
                {
                    if (numbers.Contains(value[i]))
                        throw new FormatException();
                }
                _majorName = value;
            }
        }
        public Student() : base()
        {
            GroupName = "";
            MajorName = "";
        }
        public Student(string surname, string name, int age, string schoolName, int year, string groupName, string majorName) : base(surname, name, age, schoolName, year)
        {
            GroupName = groupName;
            MajorName = majorName;
        }
        public new void Show()
        {
            Console.WriteLine($"Student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}");
        }
        public override void Write()
        {
            Console.WriteLine($"Student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}");
        }
    }
}
