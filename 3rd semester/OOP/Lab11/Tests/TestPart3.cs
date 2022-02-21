using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Part1;
using Part3;

namespace Tests
{
    [TestClass]
    public class TestPart3
    {
        [TestMethod]
        public void TestMethod1()
        {
            TestCollections myCollections = new TestCollections(10);
            TestCollections tempMyCollections = new TestCollections();

            Schoolchild s = new Schoolchild(99999, "Сорокин", "Мем", 13, "M", "№26", 7),
                skolnik = new Schoolchild();
            tempMyCollections.AddElement(s);

            Assert.AreEqual(tempMyCollections.personsQ.Peek(), s);
            Assert.AreEqual(tempMyCollections.strQ.Peek(), s.BasePerson.ToString());
            Assert.IsTrue(tempMyCollections.srtDict1.ContainsKey(s.BasePerson));
            Assert.IsTrue(tempMyCollections.srtDict2.ContainsKey(s.BasePerson.ToString()));

            skolnik = new Schoolchild(99899, "Коков", "Тромб", 12, "M", "№29", 6);
            tempMyCollections.AddElement(skolnik);

            tempMyCollections.RemoveElement(skolnik.BasePerson);
            Assert.IsFalse(tempMyCollections.personsQ.Count > 4);
            Assert.IsTrue(tempMyCollections.strQ.Count == 1);
        }
    }
}
