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
    public partial class ChangingForm : Form
    {
        BinaryTree<IExecutable> col;
        int id = -1, index;
        public ChangingForm(ref BinaryTree<IExecutable> myCollection)
        {
            InitializeComponent();
            col = myCollection;
            textBoxName.Enabled = textBoxSurname.Enabled = buttonSendId.Enabled = false;
        }

        private void buttonSendId_Click(object sender, EventArgs e)
        {
            //int temp = col.FindAndReturnIndex(id);
            if (index > -1)
            {
                IExecutable obj = col[index];
                ((Person)obj).Name = textBoxName.Text;
                ((Person)obj).Surname = textBoxSurname.Text;
                col[index] = obj;
            }
            this.Close();
        }

        private void buttonInsert_Click(object sender, EventArgs e)
        {
            //int id;
            if (int.TryParse(textBoxId.Text, out id))
            {
                index = col.FindAndReturnIndex(id);
                if (index > -1)
                {
                    textBoxName.Enabled = textBoxSurname.Enabled = buttonSendId.Enabled = true;
                }
            }
            else
            {
                labelText.Text = "Введите id корректно";
            }
        }
    }
}
