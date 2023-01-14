using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Lab12;
using PersonLibrary;

namespace Lab16Main
{
    public partial class Form1 : Form
    {
        BinaryTree<IExecutable> myCollection;        
        public Form1()
        {
            InitializeComponent();
            myCollection = new BinaryTree<IExecutable>();
        }

        private void buttonAddedElem_Click(object sender, EventArgs e)
        {
            AdditionForm f1 = new AdditionForm(ref myCollection);
            f1.ShowDialog();
            button2_Click(sender, e);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (myCollection.Count > 0)
            {
                string p = "";
                foreach (var item in myCollection)
                {
                    p = p + item.ToShortenString() + '\n';
                }
                labelColBox.Text = p;
            }
            else
                labelColBox.Text = "Необходимо добавить элемент\n в коллекцию\n";            
        }

        private void buttonFileInsert_Click(object sender, EventArgs e)
        {
            if (myCollection.Count > 0)
            {
                SaveToFileForm f = new SaveToFileForm(ref myCollection);
                f.ShowDialog();
                button2_Click(sender, e);
            }
            else
                labelColBox.Text = "Необходимо добавить элемент\n в коллекцию\n";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (myCollection.Count > 0)
            {
                RemovingForm f = new RemovingForm(ref myCollection);
                f.ShowDialog();
                button2_Click(sender, e);
            }
            else
                labelColBox.Text = "Необходимо добавить элемент\n в коллекцию\n";
        }

        private void buttonChangeElem_Click(object sender, EventArgs e)
        {
            if (myCollection.Count > 0)
            {
                ChangingForm f = new ChangingForm(ref myCollection);
                f.ShowDialog();
                button2_Click(sender, e);
            }
            else
            {
                labelColBox.Text = "Необходимо добавить элемент\n в коллекцию\n";
            }                
        }

        private void buttonReadFile_Click(object sender, EventArgs e)
        {
            ReadFIleForm f = new ReadFIleForm(ref myCollection);
            f.ShowDialog();
            // in case if binary file was read
            myCollection = f.myCollection;
            // in case if xml or json file were read
            if (myCollection == null || myCollection.Count == 0)
            {
                BinaryTree<Person> tempCol = f.myCollectionPerson;
                myCollection.Clear();
                if (tempCol != null)
                {
                    foreach (var item in tempCol)
                    {
                        myCollection.Add(item);
                    }
                }                
            }
            button2_Click(sender, e);
        }
    }
}
