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
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Xml;
using System.Xml.Serialization;
using System.Runtime.Serialization.Json;

namespace Lab16Main
{
    public partial class SaveToFileForm : Form
    {
        BinaryTree<IExecutable> myCol;
        public SaveToFileForm(ref BinaryTree<IExecutable> myCollection)
        {
            InitializeComponent();
            myCol = myCollection;
        }

        private async void buttonSaveToText_Click(object sender, EventArgs e)
        {
            string path = "textFile.txt";
            using (StreamWriter writer = new StreamWriter(path, false))
            {
                string p = "";
                foreach (var item in myCol)
                {
                    p = p + item.ToShortenString() + '\n';
                }
                await writer.WriteAsync(p);
            }
            MessageBox.Show("Сохранение произошло");
        }

        private void buttonSaveToBin_Click(object sender, EventArgs e)
        {
            string path = "binaryFile.dat";

            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, myCol);
            }
            MessageBox.Show("Сохранение произошло");
        }

        private void buttonSaveToJson_Click(object sender, EventArgs e)
        {
            string path = "file.json";

            BinaryTree<Person> myNewCol = new BinaryTree<Person>();
            foreach (Person item in myCol)
            {
                if (item is Schoolchild)
                    myNewCol.Add(((Schoolchild)item).BasePerson);
                else
                    myNewCol.Add(item);

            }

            DataContractJsonSerializer jsonSerializer = new DataContractJsonSerializer(typeof(BinaryTree<Person>));
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {                
                jsonSerializer.WriteObject(fs, myNewCol);
            }
            MessageBox.Show("Сохранение произошло");
        }

        private void buttonSaveToXml_Click(object sender, EventArgs e)
        {
            string path = "file.xml";

            BinaryTree<Person> myNewCol = new BinaryTree<Person>();
            foreach (var item in myCol)
            {
                if (item is Schoolchild)
                    myNewCol.Add(((Schoolchild)item).BasePerson);
                else
                    myNewCol.Add(((Person)item));
            }

            XmlSerializer xmlSerialiserCollection = new XmlSerializer(typeof(BinaryTree<Person>));
            
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                xmlSerialiserCollection.Serialize(fs, myNewCol);
            }
            MessageBox.Show("Сохранение произошло");
        } 
    }
}
