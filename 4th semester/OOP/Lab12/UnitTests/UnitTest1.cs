using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Lab12;
using PersonLibrary;
using System.Collections;
using System.Collections.Generic;

namespace UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            BinaryTree<IExecutable> tree = new BinaryTree<IExecutable>(), treeClone = null;
            Person Petr = new Person(12, "Туту", "Франк", 5, "M");
            Schoolchild Igor = new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8);
            Student Oleg = new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации");
            PartTimeStudent Jole = new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135);
            tree.Show();

            tree.Add(Petr);
            tree.Add(Igor);
            tree.Add(Oleg);
            tree.Add(Jole);
            tree.Show();
            Assert.AreEqual(4, tree.Count);
            
            tree.Remove(Petr);
            tree.Show();
            Assert.AreEqual(3, tree.Count);//Console.WriteLine(tree.Count);

            //tree.Find(Jole);
            Assert.IsTrue(tree.Find(Jole));
            Assert.IsFalse(tree.Find(Petr));
            tree.Add(Petr);

            foreach (var item in tree)
            {
                Console.WriteLine(item.ToString());
            }            

            treeClone = tree.Clone();
            treeClone = new BinaryTree<IExecutable>(tree);

            Node<IExecutable> p1 = tree.Root,
                p2 = treeClone.Root;
            Assert.AreNotSame(p1, p2);
            treeClone = tree.ShallowCopy();

            tree.Clear();
        }

        [TestMethod]
        public void TestMethod2()
        {
            BinaryTree<IExecutable> tree = new BinaryTree<IExecutable>(); 
            Person Petr = new Person(12, "Туту", "Франк", 5, "M");
            Schoolchild Igor = new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8);
            Student Oleg = new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации");
            PartTimeStudent Jole = new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135);
            tree.Add(Petr);
            tree.Add(Igor);
            tree.Add(Oleg);
            tree.Add(Jole);

            BinaryTree<IExecutable> treeClone = new BinaryTree<IExecutable>(tree);
            IEnumerator enumerator = treeClone.GetEnumerator(); // получаем IEnumerator
            while (enumerator.MoveNext())   // пока не будет возвращено false
            {
                Console.WriteLine((IExecutable)enumerator.Current);
            }
            enumerator.Reset(); // сбрасываем указатель в начало массива
        }
        
        [TestMethod]
        public void TestMethod3()
        {
            BinaryTree<IExecutable> tree = new BinaryTree<IExecutable>();
            Person Petr = new Person(12, "Туту", "Франк", 5, "M");
            Schoolchild Igor = new Schoolchild(13, "Воробьёв", "Сергей", 14, "M", "№7", 8);
            Student Oleg = new Student(14, "Гитова", "Ева", 19, "F", "ПНИПУ", 2, "ТК-20-3Б", "Телекомуникации");
            PartTimeStudent Jole = new PartTimeStudent(15, "Соколова", "Анастасия", 19, "F", "ПНИПУ", 2, "ИВТ-21-1Б", "Информатика", 657987135);

            BinaryTree<IExecutable> treeClone = null;
            try
            {
                treeClone = new BinaryTree<IExecutable>(tree.Count);
            }
            catch (Exception)
            {
                tree.Add(Petr);
                tree.Add(Igor);
                tree.Add(Oleg);
                tree.Add(Jole);
                treeClone = new BinaryTree<IExecutable>(tree.Count);
            }

            foreach (var item in treeClone)
            {
                if (item != null)
                {
                    Console.WriteLine("good");
                }
            }
        }
    }
}
