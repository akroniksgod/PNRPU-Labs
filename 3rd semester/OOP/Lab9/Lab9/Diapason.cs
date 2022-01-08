using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9
{
    public class Diapason
    {
        double _x, _y;
        static int counter = 0;
        public int Count
        { 
            get { return counter; } 
        }
        public double X 
        { 
            get { return _x; }
            set 
            {
                _x = value;
            }
        }
        public double Y
        {
            get { return _y; }
            set 
            {
                if (value > X)
                    _y = value;
                else
                    throw new ArithmeticException();
            }
        }
        public Diapason()
        {
            this._x = 0;
            this._y = 0;
            counter++;
        }
        public Diapason(double x, double y)
        {
            X = x;
            Y = y;
            counter++;
        }
        public bool Intersect(Diapason diaposon2)
        {
            if (Y < diaposon2.X || X > diaposon2.Y)
                return false;
            return true;
        }
        public void Show()
        {
            Console.WriteLine($"[{X};{Y}]");
        }
        public static bool Intersects(Diapason diapason1, Diapason diapason2)
        {
            if (diapason1.Y < diapason2.X || diapason1.X > diapason2.Y)
                return false;
            return true;
        }
    }
}
