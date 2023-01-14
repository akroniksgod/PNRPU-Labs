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
    public partial class RemovingForm : Form
    {
        BinaryTree<IExecutable> col;
        public RemovingForm(ref BinaryTree<IExecutable> myCollection)
        {
            InitializeComponent();
            col = myCollection;
        }

        private void buttonSendId_Click(object sender, EventArgs e)
        {
            int id;
            if (int.TryParse(textBoxId.Text, out id))
            {
                col.Remove(id);
                this.Close();
            }
            else
            {
                labelText.Text = "Введите id корректно";
            }
        }
    }
}
