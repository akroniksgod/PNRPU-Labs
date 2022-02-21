using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections;
using System.Collections.Generic;
using Part1;
using Part2;

namespace Tests
{
    [TestClass]
    public class TestPart2
    {
        [TestMethod]
        public void TestMethod1()
        {
            /*------------------------------------------------------------------------------*/
            SortedDictionary<int, IExecutable> myDict = new SortedDictionary<int, IExecutable>();

            myDict.Add(1, new Person(12, "Туту", "Франк", 5, "M"));
            myDict.Add(2, new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8));
            myDict.Add(3, new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации"));
            myDict.Add(4, new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135));

            Assert.AreEqual(new Person(12, "Туту", "Франк", 5, "M"), myDict[1]);
            Assert.AreEqual(new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8), myDict[2]);
            Assert.AreNotEqual(new Schoolchild(199, "Воробьёв", "Алексей", 15, "M", "№15", 9), myDict[3]);
            Assert.IsTrue(new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации") == (Student)myDict[3]);
            Assert.IsFalse(new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "МГУ", 2, "КЗИ-21-2Б", "Ифнормационная безопасность", 657987135)
                == (PartTimeStudent)myDict[4]);
            /*------------------------------------------------------------------------------*/
        }
    }
}
