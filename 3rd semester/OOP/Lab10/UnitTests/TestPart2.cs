using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Part2;

namespace UnitTests
{
    [TestClass]
    public class TestPart2
    {
        [TestMethod]        
        public void TestMethod1()
        {
            Person[] peopleArray = new Person[6];
            peopleArray[0] = new Person();
            peopleArray[0].RandomiseInfo(); peopleArray[0].RandomiseInfo(); peopleArray[0].RandomiseInfo();
            peopleArray[0].Show();
            peopleArray[0].Write();
            Person pers = new Person("Лолилов","Артур", 29, "M");
            peopleArray[0] = pers;

            peopleArray[1] = new Schoolchild();
            peopleArray[1].RandomiseInfo(); peopleArray[1].RandomiseInfo(); peopleArray[1].RandomiseInfo();
            peopleArray[1].Show();
            peopleArray[1].Write();
            Schoolchild noob = new Schoolchild("Глазов", "Вадим", 16, "M", "#72", 9);noob.Show();            
            peopleArray[1] = noob;

            peopleArray[2] = new Student();
            peopleArray[2].RandomiseInfo(); peopleArray[2].RandomiseInfo(); peopleArray[2].RandomiseInfo(); peopleArray[2].RandomiseInfo();
            peopleArray[2].Show();
            peopleArray[2].Write();
            Student oleg = new Student("Лалка", "Лалка", 20, "F", "ПНИПУ", 3, "РИС-19-2Б", "Программная инженерия"),
                sasha = new Student("Грудинин", "Зорик", 19, "M", "ПНИПУ", 2, "ИВТ-20-2Б", "Информатика"); sasha.Show();
            peopleArray[2] = oleg;
            peopleArray[4] = sasha;

            peopleArray[3] = new PartTimeStudent();
            peopleArray[3].RandomiseInfo(); peopleArray[3].RandomiseInfo(); peopleArray[3].RandomiseInfo();
            peopleArray[3].Show();
            peopleArray[3].Write();
            PartTimeStudent dumb = new PartTimeStudent("Александрова", "Алина", 30, "F", "МГУ", 3, "РИС-18-1Б", "Программная инженерия", 23123),
                dumB = new PartTimeStudent("Тупин", "Глеб", 25, "M", "ПГУ", 4, "РИС-18-1Б", "Программная инженерия", 23233123); dumb.Show();
             peopleArray[3] = dumb;
            peopleArray[5] = dumB;

            Assert.AreEqual(4, ShowMaleNames(peopleArray));
            Assert.AreEqual(2, ShowAllFemaleCounter(peopleArray));
            Assert.AreEqual(2, ShowStudOfChosenYearCount(peopleArray, 3));
            Assert.AreEqual(1, ShowAllPupilNames(peopleArray));
        }
        static int ShowMaleNames(Person[] peopleArray)
        {
            int counter = 0;
            foreach (var item in peopleArray)
            {
                if (item.Gender == "M")
                {
                    item.WriteFullNames();
                    counter++;
                }
            }
            return counter;
        }        
        static int ShowAllFemaleCounter(Person[] peopleArray)
        {
            int femaleCounter = 0;
            foreach (var item in peopleArray)
            {
                if (item.Gender == "F")
                    femaleCounter++;
            }
            return femaleCounter;
        }
        static int ShowStudOfChosenYearCount(Person[] peopleArray, int yearToSearch)
        {
            int counter = 0;
            Student stud = new Student();
            foreach (var item in peopleArray)
            {
                if (item is Student && !(item is PartTimeStudent))
                {
                    stud = item as Student;
                    if (stud.Year == yearToSearch)
                        counter++;

                }
                else if (item is PartTimeStudent)
                {
                    stud = item as PartTimeStudent;
                    if (stud.Year == yearToSearch)
                        counter++;
                }
            }
            return counter;
        }
        static int ShowAllPupilNames(Person[] peopleArray)
        {
            int counter = 0;
            foreach (var item in peopleArray)
            {
                if (item is Schoolchild && !(item is Student) && !(item is PartTimeStudent))
                {
                    item.WriteFullNames();
                    counter++;
                }
            }
            return counter;
        }
    }
}
