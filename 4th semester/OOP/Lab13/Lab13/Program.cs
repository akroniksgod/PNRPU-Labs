using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab12;
using PersonLibrary;

namespace Lab13
{
    class Program
    {
        static void Main(string[] args)
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

            myNewBinaryTree.Remove(myNewBinaryTree[3]);
            myNewBinaryTree.Remove(myNewBinaryTree[2]);
            myNewBinaryTree.Remove(myNewBinaryTree[1]);
            myNewBinaryTree.Remove(myNewBinaryTree[0]);

            Console.WriteLine("Journal\n" + journal.Show());

            MyNewCollection<IExecutable> secondTree = new MyNewCollection<IExecutable>();
            secondTree.Name = "\t2-nd balanced tree";
            Journal<IExecutable> journal2 = new Journal<IExecutable>();
            secondTree.CollectionCountChanged += journal.CollectionCountChanged;
            secondTree.CollectionReferenceChanged += journal.CollectionReferenceChanged;

            secondTree.CollectionCountChanged += journal2.CollectionCountChanged;
            secondTree.CollectionReferenceChanged += journal2.CollectionReferenceChanged;

            secondTree.Add((IExecutable)p.RandomCreate());
            secondTree.Add((IExecutable)p.RandomCreate());
            secondTree.Add((IExecutable)p.RandomCreate());
            secondTree.Add((IExecutable)p.RandomCreate());

            p = (Person)p.RandomCreate();

            secondTree[3] = p;

            Console.WriteLine("Journal 2\n" + journal2.Show());
            Console.WriteLine("Journal\n" + journal.Show());
        }
    }
}
