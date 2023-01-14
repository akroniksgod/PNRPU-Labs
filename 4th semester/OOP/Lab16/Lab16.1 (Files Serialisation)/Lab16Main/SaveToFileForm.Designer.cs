
namespace Lab16Main
{
    partial class SaveToFileForm
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
            this.buttonSaveToText = new System.Windows.Forms.Button();
            this.buttonSaveToBin = new System.Windows.Forms.Button();
            this.buttonSaveToJson = new System.Windows.Forms.Button();
            this.buttonSaveToXml = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonSaveToText
            // 
            this.buttonSaveToText.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSaveToText.Location = new System.Drawing.Point(25, 38);
            this.buttonSaveToText.Name = "buttonSaveToText";
            this.buttonSaveToText.Size = new System.Drawing.Size(187, 50);
            this.buttonSaveToText.TabIndex = 0;
            this.buttonSaveToText.Text = "Сохранить в \r\nтекстовый файл";
            this.buttonSaveToText.UseVisualStyleBackColor = true;
            this.buttonSaveToText.Click += new System.EventHandler(this.buttonSaveToText_Click);
            // 
            // buttonSaveToBin
            // 
            this.buttonSaveToBin.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSaveToBin.Location = new System.Drawing.Point(25, 94);
            this.buttonSaveToBin.Name = "buttonSaveToBin";
            this.buttonSaveToBin.Size = new System.Drawing.Size(187, 50);
            this.buttonSaveToBin.TabIndex = 1;
            this.buttonSaveToBin.Text = "Сохранить в \r\nбинарный файл";
            this.buttonSaveToBin.UseVisualStyleBackColor = true;
            this.buttonSaveToBin.Click += new System.EventHandler(this.buttonSaveToBin_Click);
            // 
            // buttonSaveToJson
            // 
            this.buttonSaveToJson.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSaveToJson.Location = new System.Drawing.Point(227, 38);
            this.buttonSaveToJson.Name = "buttonSaveToJson";
            this.buttonSaveToJson.Size = new System.Drawing.Size(187, 50);
            this.buttonSaveToJson.TabIndex = 2;
            this.buttonSaveToJson.Text = "Сохранить в JSON";
            this.buttonSaveToJson.UseVisualStyleBackColor = true;
            this.buttonSaveToJson.Click += new System.EventHandler(this.buttonSaveToJson_Click);
            // 
            // buttonSaveToXml
            // 
            this.buttonSaveToXml.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonSaveToXml.Location = new System.Drawing.Point(227, 94);
            this.buttonSaveToXml.Name = "buttonSaveToXml";
            this.buttonSaveToXml.Size = new System.Drawing.Size(187, 50);
            this.buttonSaveToXml.TabIndex = 3;
            this.buttonSaveToXml.Text = "Сохранить в XML";
            this.buttonSaveToXml.UseVisualStyleBackColor = true;
            this.buttonSaveToXml.Click += new System.EventHandler(this.buttonSaveToXml_Click);
            // 
            // SaveToFileForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(456, 192);
            this.Controls.Add(this.buttonSaveToXml);
            this.Controls.Add(this.buttonSaveToJson);
            this.Controls.Add(this.buttonSaveToBin);
            this.Controls.Add(this.buttonSaveToText);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(472, 231);
            this.MinimumSize = new System.Drawing.Size(472, 231);
            this.Name = "SaveToFileForm";
            this.Text = "SaveToFileForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonSaveToText;
        private System.Windows.Forms.Button buttonSaveToBin;
        private System.Windows.Forms.Button buttonSaveToJson;
        private System.Windows.Forms.Button buttonSaveToXml;
    }
}