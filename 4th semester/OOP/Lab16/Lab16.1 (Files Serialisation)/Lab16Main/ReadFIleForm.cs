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
    public partial class ReadFIleForm : Form
    {
        public BinaryTree<IExecutable> myCollection;
        public BinaryTree<Person> myCollectionPerson;
        public ReadFIleForm(ref BinaryTree<IExecutable> myCol)
        {
            InitializeComponent();
            myCollection = myCol;
        }

        private void buttonReadBinary_Click(object sender, EventArgs e)
        {
            string path = "binaryFile.dat";
            BinaryFormatter formatter = new BinaryFormatter();
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                myCollection = (BinaryTree<IExecutable>)formatter.Deserialize(fs);
            }
            this.Close();
        }

        private void buttonReadXML_Click(object sender, EventArgs e)
        {
            string path = "file.xml";
            XmlSerializer xmlSerialiser = new XmlSerializer(typeof(BinaryTree<Person>));
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                myCollectionPerson = (BinaryTree<Person>)xmlSerialiser.Deserialize(fs);
            }
            this.Close();
        }

        private void buttonReadJson_Click(object sender, EventArgs e)
        {
            string path = "file.json";
            DataContractJsonSerializer jsonSerializer = new DataContractJsonSerializer(typeof(BinaryTree<Person>));
            using (FileStream fs = new FileStream(path, FileMode.OpenOrCreate))
            {
                myCollectionPerson = (BinaryTree<Person>)jsonSerializer.ReadObject(fs);
            }
            this.Close();
        }
    }
}
