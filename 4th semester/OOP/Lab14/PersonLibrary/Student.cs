using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonLibrary
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
        public Student(int id, string surname, string name, int age, string gen, string schoolName, int year, string groupName, string majorName) : base(id, surname, name, age, gen, schoolName, year)
        {
            GroupName = groupName;
            MajorName = majorName;
        }
        public override object RandomCreate()
        {
            Schoolchild personToReturn = (Schoolchild)base.RandomCreate();

            string[] schoolNames = { "МГУ", "ПНИПУ", "ПГУ", "СПБГУ", "СПБПУ", "МГТУ" },
                groupNames = { "ИВТ-20-2Б", "РИС-20-2Б", "ИВТ-20-1Б", "РИС-20-1Б" },
                majors = { "Информатика", "Программная инженерия", "Робототехника" };

            return new Student(personToReturn._id._number, personToReturn.Surname, personToReturn.Name, personToReturn.Age,
                    personToReturn.Gender, schoolNames[rnd.Next(0, schoolNames.Length - 1)], rnd.Next(1, 5),
                    groupNames[rnd.Next(0, groupNames.Length - 1)], majors[rnd.Next(0, majors.Length - 1)]);
        }
        public override string ToString()
        {
            return "id " + this._id._number.ToString() + " " + Surname + " " + Name + " " + Age.ToString() + " лет, " + SchoolName + ", курс "
                + Year.ToString() + ", группа " + GroupName + ", направление " + MajorName;
        }
        public override void Write()
        {
            Console.WriteLine($"Student: {Surname} {Name} {Age} лет, {SchoolName}, курс {Year}, группа {GroupName}, направление {MajorName}");
        }
        public override object Clone()
        {
            return new Student(this._id._number, Surname, Name, Age, Gender, SchoolName, Year, GroupName, MajorName);
        }
        public override object ShallowClone()
        {
            return this.MemberwiseClone();
        }
        public static bool operator ==(Student obj1, Student obj2)
        {
            return (Schoolchild)obj1 == (Schoolchild)obj2 && obj1.GroupName == obj2.GroupName
                && obj1.MajorName == obj2.MajorName;
            // obj1._id._number == obj2._id._number && obj1.Surname == obj2.Surname && obj1.Name == obj2.Name && obj1.Age == obj2.Age;
        }
        public static bool operator !=(Student obj1, Student obj2)
        {
            return !(obj1 == obj2);
        }
        public override bool Equals(object obj)
        {
            if (obj is Student && !(obj is PartTimeStudent))
            {
                Student p = (Student)obj;
                return this == p;
            }
            return false;
        }
    }
}
