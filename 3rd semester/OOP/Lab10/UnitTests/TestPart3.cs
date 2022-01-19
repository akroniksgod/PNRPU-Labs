using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Part3;

namespace UnitTests
{
    [TestClass]
    public class TestPart3
    {
        [TestMethod]
        public void TestMethod1()
        {
            int size = 4;
            IExecutable[] arr = new IExecutable[size];
            
            Person p = new Person();
            p = (Person)p.RandomCreate();
            p = new Person(12, "Туту", "Франк", 5, "M");
            p._id.ToString();
            arr[0] = p;
            p.Write(); p.WriteFullNames(); p.ToString();

            p = new Schoolchild();
            p = (Schoolchild)p.RandomCreate();
            p = new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8);
            arr[1] = p;
            p.Write(); p.WriteFullNames(); p.ToString();

            p = new Student();
            p = (Student)p.RandomCreate();
            p = new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации");
            arr[2] = p;
            p.Write(); p.WriteFullNames(); p.ToString();

            p = new PartTimeStudent();
            p = (PartTimeStudent)p.RandomCreate();
            p = new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135);
            arr[3] = p;
            Assert.AreEqual(22, p.Counter);
            p.Write(); p.WriteFullNames(); p.ToString();

            //equals test
            Assert.AreEqual(new Person(12, "Туту", "Франк", 5, "M"), arr[0]);
            Assert.IsTrue(new Person(12, "Туту", "Франк", 5, "M") == (Person)arr[0]);
            Assert.IsFalse(new Person(12, "Туту", "Франк", 5, "M") != (Person)arr[0]);
            Assert.IsTrue(new Person(12, "Туту", "Hsajk", 5, "M") != (Person)arr[0]);
            
            Assert.AreEqual(new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8), arr[1]);
            Assert.IsTrue(new Schoolchild(13, "Воробьёв", "Сергей", 15, "M", "№1", 9) != (Schoolchild)arr[1]);

            Assert.AreEqual(new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации"), arr[2]);
            Assert.IsTrue(new Student(14, "Гитова", "Ева", 20, "F", "ПГНИУ", 3, "ТК-20-3Б", "Телекомуникации") != (Student)arr[2]);

            Assert.AreEqual(new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135), arr[3]);
            Assert.IsTrue(new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПГНИУ", 3, "ИВТ-20-1Б", "Информатика", 657987135) != (PartTimeStudent)arr[3]);

            //sorted by surname criteria
            Array.Sort(arr);
            Assert.IsTrue((Person)arr[2] == p);
            Assert.IsFalse(new Person(1133, "Филин", "Александр", 55, "M") == (Person)arr[3]);
            Assert.IsTrue(new Person(1133, "Филин", "Александр", 55, "M") != (Person)arr[3]);

            //sorted by age criteria
            Array.Sort(arr, new CompareByAge());
            Assert.AreEqual(0, Array.BinarySearch(arr, new Person { Age = 5 }, new CompareByAge()));
            Assert.IsTrue((Schoolchild)arr[1] == new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8));

            //deep cloning test
            p = null;
            p = (PartTimeStudent)arr[3];
            p = (PartTimeStudent)p.Clone();
            Assert.AreNotSame(p, arr[3]);

            p = null;
            p = (Student)arr[2];
            p = (Student)p.Clone();
            Assert.AreNotSame(p, arr[2]);
            
            p = null;
            p = (Schoolchild)arr[1];
            p = (Schoolchild)p.Clone();
            Assert.AreNotSame(p, arr[1]);
            
            p = null;
            p = (Person)arr[0];
            p = (Person)p.Clone();
            Assert.AreNotSame(p, arr[0]);

            //shallow cloning test
            p = null;
            p = (PartTimeStudent)arr[3];
            p = (PartTimeStudent)p.ShallowClone();
            p._id._number = 9;
            Assert.AreEqual(9, ((PartTimeStudent)arr[3])._id._number);

            p = null;
            p = (Student)arr[2];
            p = (Student)p.ShallowClone();
            p._id._number = 9;
            Assert.AreEqual(9, ((Student)arr[2])._id._number);

            p = null;
            p = (Schoolchild)arr[1];
            p = (Schoolchild)p.ShallowClone();
            p._id._number = 9;
            Assert.AreEqual(9, ((Schoolchild)arr[1])._id._number);

            p = null;
            p = (Person)arr[0];
            p = (Person)p.ShallowClone();
            p._id._number = 9;
            Assert.AreEqual(9, ((Person)arr[0])._id._number);
        }        
    }
}
