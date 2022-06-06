using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Lab13;
using Lab12;
using PersonLibrary;

namespace UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            MyNewCollection<IExecutable> myNewBinaryTree = new MyNewCollection<IExecutable>();
            myNewBinaryTree.Name = "\t1-st balanced tree";

            Journal<IExecutable> journal = new Journal<IExecutable>();
            myNewBinaryTree.CollectionCountChanged += journal.CollectionCountChanged;
            myNewBinaryTree.CollectionReferenceChanged += journal.CollectionReferenceChanged;

            Person p = new Person();

            myNewBinaryTree.Add((IExecutable)p.RandomCreate());
            myNewBinaryTree.Add((IExecutable)p.RandomCreate());
            myNewBinaryTree.Add((IExecutable)p.RandomCreate());
            myNewBinaryTree.Add((IExecutable)p.RandomCreate());

            myNewBinaryTree[0] = (Person)p.RandomCreate();
            myNewBinaryTree[1] = (Person)p.RandomCreate();
            myNewBinaryTree[2] = (Person)p.RandomCreate();

            myNewBinaryTree.Remove(myNewBinaryTree[3]);
            myNewBinaryTree.Remove(myNewBinaryTree[2]);
            myNewBinaryTree.Remove(myNewBinaryTree[1]);
            myNewBinaryTree.Remove(myNewBinaryTree[0]);

            

            Console.WriteLine("Journal\n" + journal.Show());
        }
    }
}
