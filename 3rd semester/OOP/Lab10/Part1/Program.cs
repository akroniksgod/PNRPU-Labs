using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Печать с помощью overloaded методов");
            Person human = new Person("Иванов", "Иван", 29), tempHuman = new Person();
            human.Show();
            Schoolchild schoolBoy = new Schoolchild("Трутнев", "Глеб", 15, "школа 75", 8);
            schoolBoy.Show();
            Student petr = new Student("Кривов", "Артём", 21, "ПНИПУ", 3, "ИВТ-19-2Б", "Информатика");
            petr.Show();
            PartTimeStudent igor = new PartTimeStudent("Пауков", "Сергей", 26, "МГУ", 2, "СДЭ-20-2Б", "Экспертиза", 4679891135);
            igor.Show();

            //showing IGNORANCE use
            Console.WriteLine("\nПример без использования слова virtual");
            tempHuman = human;
            human = igor;
            human.Show();

            //showing PROPER use
            Person[] containerOfPeople = new Person[4];

            containerOfPeople[0] = tempHuman; //класс Person
            containerOfPeople[1] = schoolBoy; //класс Schoolchild
            containerOfPeople[2] = petr;      //класс Student
            containerOfPeople[3] = igor;      //класс PartTimeStudent

            Console.WriteLine("\nПечать с помощью overrided методов");
            foreach (Person item in containerOfPeople)
            {
                item.Write();
            }
        }
    }
}
