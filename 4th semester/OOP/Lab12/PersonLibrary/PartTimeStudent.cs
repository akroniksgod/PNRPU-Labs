using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonLibrary
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
        public PartTimeStudent(int id, string surname, string name, int age, string gen, string schoolName, int year, string groupName, string majorName, long workCardNum)
            : base(id, surname, name, age, gen, schoolName, year, groupName, majorName)
        {
            WorkCardNumber = workCardNum;
        }
        public override object RandomCreate()
        {
            Student personToReturn = (Student)base.RandomCreate();

            return new PartTimeStudent(personToReturn._id._number, personToReturn.Surname, personToReturn.Name, personToReturn.Age,
                    personToReturn.Gender, personToReturn.SchoolName, personToReturn.Year,
                    personToReturn.GroupName, personToReturn.MajorName, rnd.Next(1231233, 9999999));
        }
        public override string ToString()
        {
            return "id " + this._id._number.ToString() + " " + Surname + " " + Name + " " + Age.ToString() + " лет, " + SchoolName + ", курс "
                + Year.ToString() + ", группа " + GroupName + ", направление " + MajorName
                + ", трудовая книжка " + WorkCardNumber;
        }
        public override void Write()
        {
            Console.WriteLine($"Part-time student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}, трудовая книжка: {WorkCardNumber}");
        }
        public override object Clone()
        {
            return new PartTimeStudent(this._id._number, Surname, Name, Age, Gender, SchoolName, Year, GroupName, MajorName, WorkCardNumber);
        }
        public override object ShallowClone()
        {
            return this.MemberwiseClone();
        }
        public static bool operator ==(PartTimeStudent obj1, PartTimeStudent obj2)
        {
            return (Student)obj1 == (Student)obj2 && obj1.WorkCardNumber == obj2.WorkCardNumber;
            // obj1._id._number == obj2._id._number && obj1.Surname == obj2.Surname && obj1.Name == obj2.Name && obj1.Age == obj2.Age;
        }
        public static bool operator !=(PartTimeStudent obj1, PartTimeStudent obj2)
        {
            return !(obj1 == obj2);
        }
        public override bool Equals(object obj)
        {
            if (obj is PartTimeStudent)
            {
                PartTimeStudent p = (PartTimeStudent)obj;
                return this == p;
            }
            return false;
        }
    }
}
