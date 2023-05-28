
namespace Lab5Form
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxTypeN = new System.Windows.Forms.TextBox();
            this.textBoxTypeM = new System.Windows.Forms.TextBox();
            this.textBoxTypeL = new System.Windows.Forms.TextBox();
            this.labelN = new System.Windows.Forms.Label();
            this.labelM = new System.Windows.Forms.Label();
            this.labelL = new System.Windows.Forms.Label();
            this.buttonCount = new System.Windows.Forms.Button();
            this.labelPermutResult = new System.Windows.Forms.Label();
            this.checkBoxComb = new System.Windows.Forms.CheckBox();
            this.checkBoxPartPerm = new System.Windows.Forms.CheckBox();
            this.checkBoxPermut = new System.Windows.Forms.CheckBox();
            this.radioButtonWithReps = new System.Windows.Forms.RadioButton();
            this.radioButtonWithoutReps = new System.Windows.Forms.RadioButton();
            this.labelPermut = new System.Windows.Forms.Label();
            this.labelPartPermut = new System.Windows.Forms.Label();
            this.labelPartPermutResult = new System.Windows.Forms.Label();
            this.labelComb = new System.Windows.Forms.Label();
            this.labelCombResult = new System.Windows.Forms.Label();
            this.labelActions = new System.Windows.Forms.Label();
            this.labelActionsResult = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxTypeN
            // 
            this.textBoxTypeN.Location = new System.Drawing.Point(54, 203);
            this.textBoxTypeN.Name = "textBoxTypeN";
            this.textBoxTypeN.Size = new System.Drawing.Size(100, 20);
            this.textBoxTypeN.TabIndex = 0;
            // 
            // textBoxTypeM
            // 
            this.textBoxTypeM.Location = new System.Drawing.Point(51, 278);
            this.textBoxTypeM.Name = "textBoxTypeM";
            this.textBoxTypeM.Size = new System.Drawing.Size(100, 20);
            this.textBoxTypeM.TabIndex = 1;
            // 
            // textBoxTypeL
            // 
            this.textBoxTypeL.Location = new System.Drawing.Point(51, 340);
            this.textBoxTypeL.Name = "textBoxTypeL";
            this.textBoxTypeL.Size = new System.Drawing.Size(100, 20);
            this.textBoxTypeL.TabIndex = 2;
            // 
            // labelN
            // 
            this.labelN.AutoSize = true;
            this.labelN.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelN.Location = new System.Drawing.Point(52, 181);
            this.labelN.Name = "labelN";
            this.labelN.Size = new System.Drawing.Size(81, 20);
            this.labelN.TabIndex = 3;
            this.labelN.Text = "Ввести n:";
            // 
            // labelM
            // 
            this.labelM.AutoSize = true;
            this.labelM.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelM.Location = new System.Drawing.Point(52, 247);
            this.labelM.Name = "labelM";
            this.labelM.Size = new System.Drawing.Size(85, 20);
            this.labelM.TabIndex = 4;
            this.labelM.Text = "Ввести m:";
            // 
            // labelL
            // 
            this.labelL.AutoSize = true;
            this.labelL.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelL.Location = new System.Drawing.Point(52, 320);
            this.labelL.Name = "labelL";
            this.labelL.Size = new System.Drawing.Size(75, 20);
            this.labelL.TabIndex = 5;
            this.labelL.Text = "Ввести l:";
            // 
            // buttonCount
            // 
            this.buttonCount.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonCount.Location = new System.Drawing.Point(526, 329);
            this.buttonCount.Name = "buttonCount";
            this.buttonCount.Size = new System.Drawing.Size(123, 31);
            this.buttonCount.TabIndex = 6;
            this.buttonCount.Text = "Посчитать";
            this.buttonCount.UseVisualStyleBackColor = true;
            this.buttonCount.Click += new System.EventHandler(this.buttonCount_Click);
            // 
            // labelPermutResult
            // 
            this.labelPermutResult.AutoSize = true;
            this.labelPermutResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPermutResult.Location = new System.Drawing.Point(631, 230);
            this.labelPermutResult.Name = "labelPermutResult";
            this.labelPermutResult.Size = new System.Drawing.Size(18, 20);
            this.labelPermutResult.TabIndex = 7;
            this.labelPermutResult.Text = "0";
            // 
            // checkBoxComb
            // 
            this.checkBoxComb.AutoSize = true;
            this.checkBoxComb.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBoxComb.Location = new System.Drawing.Point(56, 93);
            this.checkBoxComb.Name = "checkBoxComb";
            this.checkBoxComb.Size = new System.Drawing.Size(111, 24);
            this.checkBoxComb.TabIndex = 8;
            this.checkBoxComb.Text = "Сочетания";
            this.checkBoxComb.UseVisualStyleBackColor = true;
            // 
            // checkBoxPartPerm
            // 
            this.checkBoxPartPerm.AutoSize = true;
            this.checkBoxPartPerm.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBoxPartPerm.Location = new System.Drawing.Point(56, 70);
            this.checkBoxPartPerm.Name = "checkBoxPartPerm";
            this.checkBoxPartPerm.Size = new System.Drawing.Size(124, 24);
            this.checkBoxPartPerm.TabIndex = 9;
            this.checkBoxPartPerm.Text = "Размещения";
            this.checkBoxPartPerm.UseVisualStyleBackColor = true;
            // 
            // checkBoxPermut
            // 
            this.checkBoxPermut.AutoSize = true;
            this.checkBoxPermut.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBoxPermut.Location = new System.Drawing.Point(56, 47);
            this.checkBoxPermut.Name = "checkBoxPermut";
            this.checkBoxPermut.Size = new System.Drawing.Size(137, 24);
            this.checkBoxPermut.TabIndex = 10;
            this.checkBoxPermut.Text = "Перестановки";
            this.checkBoxPermut.UseVisualStyleBackColor = true;
            // 
            // radioButtonWithReps
            // 
            this.radioButtonWithReps.AutoSize = true;
            this.radioButtonWithReps.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonWithReps.Location = new System.Drawing.Point(243, 57);
            this.radioButtonWithReps.Name = "radioButtonWithReps";
            this.radioButtonWithReps.Size = new System.Drawing.Size(152, 24);
            this.radioButtonWithReps.TabIndex = 11;
            this.radioButtonWithReps.TabStop = true;
            this.radioButtonWithReps.Text = "С повторениями";
            this.radioButtonWithReps.UseVisualStyleBackColor = true;
            // 
            // radioButtonWithoutReps
            // 
            this.radioButtonWithoutReps.AutoSize = true;
            this.radioButtonWithoutReps.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.radioButtonWithoutReps.Location = new System.Drawing.Point(243, 93);
            this.radioButtonWithoutReps.Name = "radioButtonWithoutReps";
            this.radioButtonWithoutReps.Size = new System.Drawing.Size(149, 24);
            this.radioButtonWithoutReps.TabIndex = 12;
            this.radioButtonWithoutReps.TabStop = true;
            this.radioButtonWithoutReps.Text = "Без повторений";
            this.radioButtonWithoutReps.UseVisualStyleBackColor = true;
            // 
            // labelPermut
            // 
            this.labelPermut.AutoSize = true;
            this.labelPermut.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPermut.Location = new System.Drawing.Point(507, 230);
            this.labelPermut.Name = "labelPermut";
            this.labelPermut.Size = new System.Drawing.Size(118, 20);
            this.labelPermut.TabIndex = 13;
            this.labelPermut.Text = "Перестановки";
            // 
            // labelPartPermut
            // 
            this.labelPartPermut.AutoSize = true;
            this.labelPartPermut.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPartPermut.Location = new System.Drawing.Point(507, 264);
            this.labelPartPermut.Name = "labelPartPermut";
            this.labelPartPermut.Size = new System.Drawing.Size(105, 20);
            this.labelPartPermut.TabIndex = 14;
            this.labelPartPermut.Text = "Размещения";
            // 
            // labelPartPermutResult
            // 
            this.labelPartPermutResult.AutoSize = true;
            this.labelPartPermutResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelPartPermutResult.Location = new System.Drawing.Point(631, 264);
            this.labelPartPermutResult.Name = "labelPartPermutResult";
            this.labelPartPermutResult.Size = new System.Drawing.Size(18, 20);
            this.labelPartPermutResult.TabIndex = 15;
            this.labelPartPermutResult.Text = "0";
            // 
            // labelComb
            // 
            this.labelComb.AutoSize = true;
            this.labelComb.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelComb.Location = new System.Drawing.Point(507, 292);
            this.labelComb.Name = "labelComb";
            this.labelComb.Size = new System.Drawing.Size(92, 20);
            this.labelComb.TabIndex = 16;
            this.labelComb.Text = "Сочетания";
            // 
            // labelCombResult
            // 
            this.labelCombResult.AutoSize = true;
            this.labelCombResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCombResult.Location = new System.Drawing.Point(631, 292);
            this.labelCombResult.Name = "labelCombResult";
            this.labelCombResult.Size = new System.Drawing.Size(18, 20);
            this.labelCombResult.TabIndex = 17;
            this.labelCombResult.Text = "0";
            // 
            // labelActions
            // 
            this.labelActions.AutoSize = true;
            this.labelActions.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelActions.Location = new System.Drawing.Point(239, 170);
            this.labelActions.Name = "labelActions";
            this.labelActions.Size = new System.Drawing.Size(83, 20);
            this.labelActions.TabIndex = 18;
            this.labelActions.Text = "Действия";
            // 
            // labelActionsResult
            // 
            this.labelActionsResult.AutoSize = true;
            this.labelActionsResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelActionsResult.Location = new System.Drawing.Point(239, 201);
            this.labelActionsResult.Name = "labelActionsResult";
            this.labelActionsResult.Size = new System.Drawing.Size(52, 20);
            this.labelActionsResult.TabIndex = 19;
            this.labelActionsResult.Text = "empty";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Lab5Form.Properties.Resources.backgr;
            this.ClientSize = new System.Drawing.Size(706, 401);
            this.Controls.Add(this.labelActionsResult);
            this.Controls.Add(this.labelActions);
            this.Controls.Add(this.labelCombResult);
            this.Controls.Add(this.labelComb);
            this.Controls.Add(this.labelPartPermutResult);
            this.Controls.Add(this.labelPartPermut);
            this.Controls.Add(this.labelPermut);
            this.Controls.Add(this.radioButtonWithoutReps);
            this.Controls.Add(this.radioButtonWithReps);
            this.Controls.Add(this.checkBoxPermut);
            this.Controls.Add(this.checkBoxPartPerm);
            this.Controls.Add(this.checkBoxComb);
            this.Controls.Add(this.labelPermutResult);
            this.Controls.Add(this.buttonCount);
            this.Controls.Add(this.labelL);
            this.Controls.Add(this.labelM);
            this.Controls.Add(this.labelN);
            this.Controls.Add(this.textBoxTypeL);
            this.Controls.Add(this.textBoxTypeM);
            this.Controls.Add(this.textBoxTypeN);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(722, 440);
            this.MinimumSize = new System.Drawing.Size(722, 440);
            this.Name = "Form1";
            this.Text = "Lab5";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxTypeN;
        private System.Windows.Forms.TextBox textBoxTypeM;
        private System.Windows.Forms.TextBox textBoxTypeL;
        private System.Windows.Forms.Label labelN;
        private System.Windows.Forms.Label labelM;
        private System.Windows.Forms.Label labelL;
        private System.Windows.Forms.Button buttonCount;
        private System.Windows.Forms.Label labelPermutResult;
        private System.Windows.Forms.CheckBox checkBoxComb;
        private System.Windows.Forms.CheckBox checkBoxPartPerm;
        private System.Windows.Forms.CheckBox checkBoxPermut;
        private System.Windows.Forms.RadioButton radioButtonWithReps;
        private System.Windows.Forms.RadioButton radioButtonWithoutReps;
        private System.Windows.Forms.Label labelPermut;
        private System.Windows.Forms.Label labelPartPermut;
        private System.Windows.Forms.Label labelPartPermutResult;
        private System.Windows.Forms.Label labelComb;
        private System.Windows.Forms.Label labelCombResult;
        private System.Windows.Forms.Label labelActions;
        private System.Windows.Forms.Label labelActionsResult;
    }
}

