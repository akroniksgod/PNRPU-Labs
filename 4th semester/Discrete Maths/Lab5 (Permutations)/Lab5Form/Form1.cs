using System;
using System.Collections.Generic;
using System.Numerics;
using System.Windows.Forms;

namespace Lab5Form
{
    public partial class Form1 : Form
    {
        private int _N, _M;

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonCount_Click(object sender, EventArgs e)
        {
            labelActionsResult.Text = "";
            labelCombResult.Text = labelPartPermutResult.Text = labelPermutResult.Text = 0.ToString();
            if (int.TryParse(textBoxTypeN.Text, out _N) && int.TryParse(textBoxTypeM.Text, out _M) && textBoxTypeL.Text.Length > 0//int.TryParse(.Text, out _L) 
                && (radioButtonWithoutReps.Checked || radioButtonWithReps.Checked))
            {
                if (radioButtonWithoutReps.Checked)
                {
                    if (checkBoxPermut.Checked)
                        PermutationWithoutReps(_N);

                    if (checkBoxPartPerm.Checked)
                        PartialPermutationWithoutReps(_N, _M);

                    if (checkBoxComb.Checked)
                        CombinationWithoutReps(_N, _M);
                }
                else if (radioButtonWithReps.Checked)
                {
                    if (checkBoxPermut.Checked)
                        PermutationWithReps(_N);

                    if (checkBoxPartPerm.Checked)
                        PartialPermutationWithReps(_N, _M);

                    if (checkBoxComb.Checked)
                        CombinationWithReps(_N, _M);
                }
            }
        }

        private void CombinationWithReps(int n, int m)
        {
            BigInteger factN_Minus_1 = Factorial(n - 1),
                factM = Factorial(m),
                factN_Plus_M_Minus_1 = Factorial(n + m - 1);

            labelActionsResult.Text = labelActionsResult.Text + "\n"
                + (n - 1) + "!\n" + "------------------\n(" + (n + m - 1) + ")! * " + m + "!\n";

            BigInteger res = factN_Plus_M_Minus_1 / (factM * factN_Minus_1);
            labelCombResult.Text = res.ToString();
        }

        private void PartialPermutationWithReps(int n, int m)
        {
            BigInteger res = (BigInteger)Math.Pow(n, m);
            labelActionsResult.Text = labelActionsResult.Text + "\n"
                + n + "^" + m + "\n";
            labelPartPermutResult.Text = res.ToString();
        }

        private void PermutationWithReps(int n)
        {
            bool isParsed = true;
            BigInteger factN = Factorial(n);            
            List<int> v = new List<int>();

            string[] arr = textBoxTypeL.Text.Split(' ');
            for (int i = 0; i < arr.Length && isParsed; i++)
            {
                int temp;
                if (int.TryParse(arr[i], out temp))
                    v.Add(temp);
                else
                    isParsed = false;
            }

            if (!isParsed)
                labelPermutResult.Text = "Ошибка";

            string toPrint = "";
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = arr[i] + "!";
                if (i != 0)
                    toPrint = toPrint + " * "  + arr[i];
                else
                    toPrint = toPrint + arr[i];
            }

            BigInteger zn = 1;
            for (int i = 0; i < v.Count; i++)
            {
                BigInteger temp = Factorial(v[i]);
                zn *= temp;
            }

            labelActionsResult.Text = labelActionsResult.Text
                + n + "!\n" + "------------------\n" + toPrint + "\n";

            BigInteger res = factN / zn;

            labelPermutResult.Text = res.ToString();
        }

        private void CombinationWithoutReps(int n, int m)
        {
            BigInteger factN = Factorial(n),
                factM = Factorial(m),
                factN_Minus_M = Factorial(n - m);

            labelActionsResult.Text = labelActionsResult.Text + "\n"
                + n + "!\n" + "------------------\n(" + n + " - " + m + ")! * " + m + "!\n";

            BigInteger res = factN / (factM * factN_Minus_M);
            labelCombResult.Text = res.ToString();
        }

        private void PartialPermutationWithoutReps(int n, int m)
        {
            if (n - m > 0)
            {
                BigInteger factN = Factorial(n),
                    factN_Minus_N = Factorial(n - m);

                labelActionsResult.Text = labelActionsResult.Text + "\n"
                + n + "!\n" + "------------------\n(" + n + " - " + m + ")!\n";

                BigInteger res = (factN / factN_Minus_N);
                labelPartPermutResult.Text = res.ToString();
            }
            else
                labelPartPermutResult.Text = "Невозможно посчитать";
        }

        private void PermutationWithoutReps(int n)
        {
            BigInteger factN = Factorial(n);
            labelActionsResult.Text = labelActionsResult.Text
                + n + "! = " + factN + "\n";
            labelPermutResult.Text = factN.ToString();
        }

        private BigInteger Factorial(int n)
        {
            BigInteger a = 1;
            for (BigInteger i = 1; i <= (BigInteger)n && n != 1 && n != 0; i++)
            {
                a *= i;
            }
            return a;
        }
    }
}