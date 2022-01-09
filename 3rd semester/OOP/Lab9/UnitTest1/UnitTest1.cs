using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Lab9;

namespace UnitTest1
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Diapason d0 = new Diapason();
            //checking if diapasons intersect each other

            //1 theese should intersect each other
            Diapason d1 = new Diapason(4, 8);
            Diapason d2 = new Diapason(6, 9);
            Assert.AreEqual(true, d1.Intersect(d2));

            //2 theese should NOT intersect each other
            Diapason d3 = new Diapason(4, 8);
            Diapason d4 = new Diapason(9, 12);
            Assert.IsFalse(d4.Intersect(d3));

            //3 theese should intersect each other
            Diapason d5 = new Diapason(4, 8);
            Diapason d6 = new Diapason(8, 12.7);
            Assert.IsTrue(d5.Intersect(d6));

            //4 theese should intersect each other
            Diapason d7 = new Diapason(4, 8);
            Diapason d8 = new Diapason(1, 4);
            Assert.IsTrue(Diapason.Intersects(d7, d8));

            Assert.AreEqual(9, d8.Count);

            d8.Show();
        }
    }
}
