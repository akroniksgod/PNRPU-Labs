using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp
{
    public partial class Lab15App : Form
    {
        private object _locker = new object();
        public Random rand = new Random();
        private List<PointF> _points = new List<PointF>();
        public float lowerBound, upperBound, _x, _y;
        public Lab15App()
        {
            InitializeComponent();
        }

        private void buttonInputDiapason_Click(object sender, EventArgs e)
        {
            float leftB, rightB;
            Graphic.Series[0].Points.Clear();
            _points.Clear();
            if (float.TryParse(textBoxLeftBorder.Text, out leftB) && float.TryParse(textBoxRightBorder.Text, out rightB))
            {
                if (leftB < rightB)
                {
                    labelBorders.Text = "Введите границы рассчёта: Успех";
                    Thread t1 = new Thread(new ThreadStart(Count));
                    Thread t2 = new Thread(new ThreadStart(Print));
                    t1.Name = "CountThread";
                    t2.Name = "PrintThread";
                    t1.IsBackground = true;
                    t2.IsBackground = true;

                    _x = lowerBound = leftB;
                    upperBound = rightB;

                    t1.Start();
                    t2.Start();

                    t1.Priority = ThreadPriority.Highest;
                }
                else
                    labelBorders.Text = "Введите границы рассчёта:\nНеправильный диапазон";
            }
            else
                labelBorders.Text = "Введите границы рассчёта: Ошибка";
        }
        private void Count()
        {
            while (_x <= upperBound)
            {
                lock (_locker)
                {
                    _x += 0.01f;
                    _y = 23 * _x * _x - 33;                   
                }
                Thread.Sleep(100);
            }
        }
        private void Print()
        {
            while (_x <= upperBound)
            {
                lock (_locker)
                {
                    _points.Add(new PointF(_x, _y));

                    if (_points.Count > 1000)
                        _points.RemoveAt(0);
                }
                Thread.Sleep(500);
            }
        }
        private void GraphicTimer_Tick(object sender, EventArgs e)
        {
            Graphic.Series[0].Points.Clear();
            lock (_locker)
            {
                foreach (var point in _points)
                {
                    Graphic.Series[0].Points.AddXY(point.X, point.Y);
                }

                PointsLog.Text = "Точки:\n";
                for (int i = _points.Count - 6; i < _points.Count; i++)
                {
                    if (i >= 0)
                        PointsLog.Text += $"X={_points[i].X:0.000}, Y={_points[i].Y:0.000}\n";
                }
            }
        }
    }
}
