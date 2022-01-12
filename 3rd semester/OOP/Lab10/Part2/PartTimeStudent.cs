using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part2
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
        public PartTimeStudent(string surname, string name, int age, string gen, string schoolName, int year, string groupName, string majorName, long workCardNum) : base(surname, name, age, gen, schoolName, year, groupName, majorName)
        {
            WorkCardNumber = workCardNum;
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
            Age = rnd.Next(18, 50);
            SchoolName = schoolNames[rnd.Next(0, schoolNames.Length - 1)];
            Year = rnd.Next(1, 6);
            GroupName = groupNames[rnd.Next(0, groupNames.Length - 1)];
            MajorName = majors[rnd.Next(0, majors.Length - 1)];
            WorkCardNumber = rnd.Next(1231233, 9999999);
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
