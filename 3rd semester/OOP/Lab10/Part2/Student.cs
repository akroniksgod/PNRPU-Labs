using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
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
        public Student(string surname, string name, int age, string gen, string schoolName, int year, string groupName, string majorName) : base(surname, name, age, gen, schoolName, year)
        {
            GroupName = groupName;
            MajorName = majorName;
        }
        public override void RandomiseInfo()
        {
            string[] maleNames = { "Александр", "Алексей", "Артур", "Бен", "Владимир", "Пётр", "Николай", "Максим" },
                femaleNames = { "Екатерина", "Анастасия", "Вероника", "Ева", "Ирина" },
                maleSurnames = { "Петров", "Иванов", "Алалуев", "Кукуев", "Занзибар", "Лоскутов", "Замарёв" },
                femaleSurnames = { "Замарёва", "Замбарёва", "Тедешка", "Петрова", "Стоматологова", "Пупкова" },
                schoolNames = { "МГУ", "ПНИПУ", "ПГУ", "СПБГУ", "СПБПУ", "МГТУ" },
                groupNames = { "ИВТ-20-2Б", "РИС-20-2Б", "ИВТ-20-1Б", "РИС-20-1Б" },
                majors = { "Информатика", "Программная инженерия", "Робототехника" };

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
            Age = rnd.Next(18, 25);
            SchoolName = schoolNames[rnd.Next(0, schoolNames.Length - 1)];
            Year = rnd.Next(1, 5);
            GroupName = groupNames[rnd.Next(0, groupNames.Length - 1)];
            MajorName = majors[rnd.Next(0, majors.Length - 1)];
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