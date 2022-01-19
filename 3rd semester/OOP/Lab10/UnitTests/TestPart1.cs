using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Part1;

namespace UnitTests
{
    [TestClass]
    public class TestPart1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Person human = new Person("Иванов", "Иван", 29), tempHuman = new Person();
            human.Show();
            Schoolchild schoolBoy = new Schoolchild("Трутнев", "Глеб", 15, "школа 75", 8), emptySchoolchild = new Schoolchild();            
            schoolBoy.Show();
            Assert.IsTrue(emptySchoolchild != schoolBoy);

            Student petr = new Student("Кривов", "Артём", 21, "ПНИПУ", 3, "ИВТ-19-2Б", "Информатика"), emptyStudent = new Student();
            petr.Show();
            Assert.IsTrue(petr != emptyStudent);

            PartTimeStudent igor = new PartTimeStudent("Пауков", "Сергей", 26, "МГУ", 2, "СДЭ-20-2Б", "Экспертиза", 4679891135), emptyPTStudent = new PartTimeStudent();
            igor.Show();
            Assert.IsFalse(emptyPTStudent == igor);
            
            //showing IGNORANCE use            
            tempHuman = human;
            Assert.IsTrue(tempHuman == human);
            Assert.IsFalse(petr == igor);
            Assert.IsTrue(human != schoolBoy);

            human = igor;
            Assert.AreEqual(igor.Surname, human.Surname);
            human.Show();

            //showing PROPER use
            Person[] containerOfPeople = new Person[4];

            containerOfPeople[0] = tempHuman;
            containerOfPeople[1] = schoolBoy;
            containerOfPeople[2] = petr;
            containerOfPeople[3] = igor;
            
            Assert.IsInstanceOfType(containerOfPeople[0], typeof(Person));
            Assert.IsInstanceOfType(containerOfPeople[1], typeof(Schoolchild));
            Assert.IsInstanceOfType(containerOfPeople[2], typeof(Student));
            Assert.IsInstanceOfType(containerOfPeople[3], typeof(PartTimeStudent));

            Console.WriteLine("\nПечать с помощью overrided методов");
            foreach (Person item in containerOfPeople)
            {
                item.Write();
            }
        }
    }
}
