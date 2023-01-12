
namespace WindowsFormsApp
{
    partial class Lab15App
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.GraphicTimer = new System.Windows.Forms.Timer(this.components);
            this.Graphic = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.PointsLog = new System.Windows.Forms.Label();
            this.buttonInputDiapason = new System.Windows.Forms.Button();
            this.textBoxLeftBorder = new System.Windows.Forms.TextBox();
            this.textBoxRightBorder = new System.Windows.Forms.TextBox();
            this.labelBorders = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.Graphic)).BeginInit();
            this.SuspendLayout();
            // 
            // GraphicTimer
            // 
            this.GraphicTimer.Enabled = true;
            this.GraphicTimer.Tick += new System.EventHandler(this.GraphicTimer_Tick);
            // 
            // Graphic
            // 
            chartArea1.Name = "ChartArea1";
            this.Graphic.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.Graphic.Legends.Add(legend1);
            this.Graphic.Location = new System.Drawing.Point(12, 12);
            this.Graphic.Name = "Graphic";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.Graphic.Series.Add(series1);
            this.Graphic.Size = new System.Drawing.Size(560, 425);
            this.Graphic.TabIndex = 0;
            this.Graphic.Text = "chart1";
            // 
            // PointsLog
            // 
            this.PointsLog.AutoSize = true;
            this.PointsLog.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PointsLog.Location = new System.Drawing.Point(12, 440);
            this.PointsLog.Name = "PointsLog";
            this.PointsLog.Size = new System.Drawing.Size(57, 20);
            this.PointsLog.TabIndex = 1;
            this.PointsLog.Text = "Точки:";
            // 
            // buttonInputDiapason
            // 
            this.buttonInputDiapason.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonInputDiapason.Location = new System.Drawing.Point(468, 496);
            this.buttonInputDiapason.Name = "buttonInputDiapason";
            this.buttonInputDiapason.Size = new System.Drawing.Size(80, 22);
            this.buttonInputDiapason.TabIndex = 2;
            this.buttonInputDiapason.Text = "Рассчёт";
            this.buttonInputDiapason.UseVisualStyleBackColor = true;
            this.buttonInputDiapason.Click += new System.EventHandler(this.buttonInputDiapason_Click);
            // 
            // textBoxLeftBorder
            // 
            this.textBoxLeftBorder.Location = new System.Drawing.Point(325, 496);
            this.textBoxLeftBorder.Name = "textBoxLeftBorder";
            this.textBoxLeftBorder.Size = new System.Drawing.Size(50, 20);
            this.textBoxLeftBorder.TabIndex = 3;
            // 
            // textBoxRightBorder
            // 
            this.textBoxRightBorder.Location = new System.Drawing.Point(394, 496);
            this.textBoxRightBorder.Name = "textBoxRightBorder";
            this.textBoxRightBorder.Size = new System.Drawing.Size(50, 20);
            this.textBoxRightBorder.TabIndex = 4;
            // 
            // labelBorders
            // 
            this.labelBorders.AutoSize = true;
            this.labelBorders.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelBorders.Location = new System.Drawing.Point(322, 461);
            this.labelBorders.Name = "labelBorders";
            this.labelBorders.Size = new System.Drawing.Size(186, 16);
            this.labelBorders.TabIndex = 5;
            this.labelBorders.Text = "Введите границы рассчёта";
            // 
            // Lab15App
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 561);
            this.Controls.Add(this.labelBorders);
            this.Controls.Add(this.textBoxRightBorder);
            this.Controls.Add(this.textBoxLeftBorder);
            this.Controls.Add(this.buttonInputDiapason);
            this.Controls.Add(this.Graphic);
            this.Controls.Add(this.PointsLog);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Lab15App";
            this.Text = "Lab15";
            ((System.ComponentModel.ISupportInitialize)(this.Graphic)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer GraphicTimer;
        private System.Windows.Forms.DataVisualization.Charting.Chart Graphic;
        private System.Windows.Forms.Label PointsLog;
        private System.Windows.Forms.Button buttonInputDiapason;
        private System.Windows.Forms.TextBox textBoxLeftBorder;
        private System.Windows.Forms.TextBox textBoxRightBorder;
        private System.Windows.Forms.Label labelBorders;
    }
}

