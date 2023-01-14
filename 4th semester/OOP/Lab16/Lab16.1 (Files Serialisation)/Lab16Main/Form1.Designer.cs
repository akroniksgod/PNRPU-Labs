
namespace Lab16Main
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
            this.buttonFileInsert = new System.Windows.Forms.Button();
            this.buttonChangeElem = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.buttonAddedElem = new System.Windows.Forms.Button();
            this.labelColBox = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.buttonReadFile = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonFileInsert
            // 
            this.buttonFileInsert.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonFileInsert.Location = new System.Drawing.Point(7, 136);
            this.buttonFileInsert.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.buttonFileInsert.Name = "buttonFileInsert";
            this.buttonFileInsert.Size = new System.Drawing.Size(204, 35);
            this.buttonFileInsert.TabIndex = 0;
            this.buttonFileInsert.Text = "Записать в файл";
            this.buttonFileInsert.UseVisualStyleBackColor = true;
            this.buttonFileInsert.Click += new System.EventHandler(this.buttonFileInsert_Click);
            // 
            // buttonChangeElem
            // 
            this.buttonChangeElem.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonChangeElem.Location = new System.Drawing.Point(7, 193);
            this.buttonChangeElem.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.buttonChangeElem.Name = "buttonChangeElem";
            this.buttonChangeElem.Size = new System.Drawing.Size(204, 35);
            this.buttonChangeElem.TabIndex = 1;
            this.buttonChangeElem.Text = "Изменить объект";
            this.buttonChangeElem.UseVisualStyleBackColor = true;
            this.buttonChangeElem.Click += new System.EventHandler(this.buttonChangeElem_Click);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button1.Location = new System.Drawing.Point(7, 249);
            this.button1.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(204, 35);
            this.button1.TabIndex = 2;
            this.button1.Text = "Удалить объект";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // buttonAddedElem
            // 
            this.buttonAddedElem.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonAddedElem.Location = new System.Drawing.Point(7, 80);
            this.buttonAddedElem.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.buttonAddedElem.Name = "buttonAddedElem";
            this.buttonAddedElem.Size = new System.Drawing.Size(204, 35);
            this.buttonAddedElem.TabIndex = 3;
            this.buttonAddedElem.Text = "Добавить элемент";
            this.buttonAddedElem.UseVisualStyleBackColor = true;
            this.buttonAddedElem.Click += new System.EventHandler(this.buttonAddedElem_Click);
            // 
            // labelColBox
            // 
            this.labelColBox.AutoSize = true;
            this.labelColBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.labelColBox.Location = new System.Drawing.Point(14, 72);
            this.labelColBox.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelColBox.Name = "labelColBox";
            this.labelColBox.Size = new System.Drawing.Size(0, 20);
            this.labelColBox.TabIndex = 4;
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.button2.Location = new System.Drawing.Point(7, 23);
            this.button2.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(204, 35);
            this.button2.TabIndex = 5;
            this.button2.Text = "Посмотреть содержание";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // buttonReadFile
            // 
            this.buttonReadFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.buttonReadFile.Location = new System.Drawing.Point(7, 306);
            this.buttonReadFile.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.buttonReadFile.Name = "buttonReadFile";
            this.buttonReadFile.Size = new System.Drawing.Size(204, 35);
            this.buttonReadFile.TabIndex = 6;
            this.buttonReadFile.Text = "Чтение из файла";
            this.buttonReadFile.UseVisualStyleBackColor = true;
            this.buttonReadFile.Click += new System.EventHandler(this.buttonReadFile_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonReadFile);
            this.groupBox1.Controls.Add(this.buttonFileInsert);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.buttonChangeElem);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.buttonAddedElem);
            this.groupBox1.Location = new System.Drawing.Point(407, 52);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.groupBox1.Size = new System.Drawing.Size(220, 361);
            this.groupBox1.TabIndex = 7;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Menu";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(640, 509);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.labelColBox);
            this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(656, 548);
            this.MinimumSize = new System.Drawing.Size(656, 548);
            this.Name = "Form1";
            this.Text = "Lab16";
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonFileInsert;
        private System.Windows.Forms.Button buttonChangeElem;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button buttonAddedElem;
        private System.Windows.Forms.Label labelColBox;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button buttonReadFile;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

