using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Part3;

namespace UnitTest3
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
            Assert.IsFalse(Diapason.Intersects(d4, d3));
            Assert.IsTrue(d4 > d3);

            //3 theese should intersect each other
            Diapason d5 = new Diapason(4, 8);
            Diapason d6 = new Diapason(8, 12.7);
            Assert.IsTrue(d5 < d6);

            Assert.AreEqual(false, d1 == d4);
            Assert.AreEqual(true, d2 != d3);

            Assert.AreEqual(4, !d1);
            Assert.AreEqual(9, (double)d2);

            Diapason toCheck = d3 - 1;
            Diapason toCompare1 = new Diapason(4, 7);
            Assert.AreEqual(toCompare1, toCheck);

            Diapason toCheck2 = 1 - d4;
            Diapason toCompare2 = new Diapason(8, 12);
            Assert.AreEqual(toCheck2, toCompare2);
            Assert.AreEqual(11, d6.Count);

            DiapasonArray diapasons1 = new DiapasonArray(5);
            Assert.AreEqual(new DiapasonArray(5).Size, diapasons1.Size);
            DiapasonArray diapasons2 = new DiapasonArray(2);
            diapasons2[0] = d3;
            diapasons2[1] = d4;

            bool checkRelation = diapasons2[0] != diapasons2[1];
            Assert.IsTrue(checkRelation);
            checkRelation = diapasons2[0] == diapasons2[1];
            Assert.IsFalse(checkRelation);

            DiapasonArray diapasons3 = new DiapasonArray();
            Assert.AreEqual(4, diapasons3.Count);
            
            diapasons2.Write();
        }
    }
}
