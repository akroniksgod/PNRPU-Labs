
namespace Lab16Main
{
    partial class ReadFIleForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonReadBinary = new System.Windows.Forms.Button();
            this.buttonReadXML = new System.Windows.Forms.Button();
            this.buttonReadJson = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonReadBinary
            // 
            this.buttonReadBinary.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonReadBinary.Location = new System.Drawing.Point(83, 77);
            this.buttonReadBinary.Name = "buttonReadBinary";
            this.buttonReadBinary.Size = new System.Drawing.Size(111, 73);
            this.buttonReadBinary.TabIndex = 0;
            this.buttonReadBinary.Text = "Прочесть \r\nбинарный файл";
            this.buttonReadBinary.UseVisualStyleBackColor = true;
            this.buttonReadBinary.Click += new System.EventHandler(this.buttonReadBinary_Click);
            // 
            // buttonReadXML
            // 
            this.buttonReadXML.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonReadXML.Location = new System.Drawing.Point(140, 156);
            this.buttonReadXML.Name = "buttonReadXML";
            this.buttonReadXML.Size = new System.Drawing.Size(111, 73);
            this.buttonReadXML.TabIndex = 1;
            this.buttonReadXML.Text = "Прочесть\r\nXML файл";
            this.buttonReadXML.UseVisualStyleBackColor = true;
            this.buttonReadXML.Click += new System.EventHandler(this.buttonReadXML_Click);
            // 
            // buttonReadJson
            // 
            this.buttonReadJson.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonReadJson.Location = new System.Drawing.Point(200, 77);
            this.buttonReadJson.Name = "buttonReadJson";
            this.buttonReadJson.Size = new System.Drawing.Size(111, 73);
            this.buttonReadJson.TabIndex = 2;
            this.buttonReadJson.Text = "Прочесть\r\nJSON файл";
            this.buttonReadJson.UseVisualStyleBackColor = true;
            this.buttonReadJson.Click += new System.EventHandler(this.buttonReadJson_Click);
            // 
            // ReadFIleForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(389, 302);
            this.Controls.Add(this.buttonReadJson);
            this.Controls.Add(this.buttonReadXML);
            this.Controls.Add(this.buttonReadBinary);
            this.Name = "ReadFIleForm";
            this.Text = "ReadFIleForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonReadBinary;
        private System.Windows.Forms.Button buttonReadXML;
        private System.Windows.Forms.Button buttonReadJson;
    }
}