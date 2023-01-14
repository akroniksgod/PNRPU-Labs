using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab12;
using PersonLibrary;

namespace Lab16Main
{
    public partial class AdditionForm : Form
    {
        BinaryTree<IExecutable> col;
        static Random rnd = new Random();
        public AdditionForm(ref BinaryTree<IExecutable> myCollection)
        {
            InitializeComponent();
            col = myCollection;
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            int id;
            if (int.TryParse(textBoxElementCount.Text, out id))
            {
                FillTreeWithRandom(ref col, id);
                this.Close();
            }
            else
            {
                labelText.Text = "Введите id корректно";
            }            
        }
        static void FillTreeWithRandom(ref BinaryTree<IExecutable> myTree, int count)
        {
            //int count = InsertVariables("Введите количество элементов для добавления");
            for (int i = 0; i < count; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    myTree.Add(p);
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    myTree.Add(s);
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    myTree.Add(s);
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    myTree.Add(s);
                }
            }
            Console.WriteLine("Элементы добавлены");
        }
        static int InsertVariables(string toAsk)
        {
            int x;
            bool isParsed = false;
            do
            {
                Console.WriteLine(toAsk);
                if (int.TryParse(Console.ReadLine(), out x))
                {
                    if (x > 0)
                        isParsed = true;
                    else
                        continue;
                }
                else
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте ввести заново!");
                    continue;
                }
            } while (!isParsed);

            return x;
        }
    }
}
