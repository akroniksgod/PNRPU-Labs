using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    public class PartTimeStudent : Student
    {
        long _workCardNumber;
        public long WorkCardNumber
        {
            get { return _workCardNumber; }
            set { _workCardNumber = value; }
        }
        public PartTimeStudent() : base()
        {
            _workCardNumber = 0;
        }
        public PartTimeStudent(string surname, string name, int age, string schoolName, int year, string groupName, string majorName, long workCardNum) : base(surname, name, age, schoolName, year, groupName, majorName)
        {
            WorkCardNumber = workCardNum;
        }
        public new void Show()
        {
            Console.WriteLine($"Part-time student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}, трудовая книжка: {WorkCardNumber}");
        }
        public override void Write()
        {
            Console.WriteLine($"Part-time student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}, трудовая книжка: {WorkCardNumber}");
        }
    }
}
