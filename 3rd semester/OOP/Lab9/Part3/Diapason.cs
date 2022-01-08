using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
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
        public static bool Intersects(Diapason diapason1, Diapason diapason2)
        {
            if (diapason1.Y < diapason2.X || diapason1.X > diapason2.Y)
                return false;
            return true;
        }
        public void Show()
        {
            Console.WriteLine($"[{X};{Y}]");
        }

        public string Write()
        {
            return "[" + X + "; " + Y + "]";
        }
        //////////////// OVERLOADING \\\\\\\\\\\\\\\\\
        public static double operator !(Diapason toCount)
        {
            return toCount.Y - toCount.X;
        }
        //неявное преобразование
        public static implicit operator int(Diapason toFloor)
        {
            return (int)toFloor.X;
        }
        //явное преобразование
        public static explicit operator double(Diapason toFloor)
        {
            return toFloor.Y;
        }

        public static Diapason operator -(double number, Diapason diapason1)
        {
            return new Diapason(diapason1.X - number, diapason1.Y);
        }
        public static Diapason operator -(Diapason diapason1, double number)
        {
            return new Diapason(diapason1.X, diapason1.Y - number);
        }
        public static bool operator <(Diapason diapason1, Diapason diapason2)
        {
            if (diapason1.Y < diapason2.X || diapason1.X > diapason2.Y)
                return false;
            return true;
        }
        public static bool operator >(Diapason diapason1, Diapason diapason2)
        {
            return !(diapason1 < diapason2);
        }
        public static bool operator ==(Diapason diapason1, Diapason diapason2)
        {
            return diapason1.X == diapason2.X && diapason1.Y == diapason2.Y;
        }
        public static bool operator !=(Diapason diapason1, Diapason diapason2)
        {
            return !(diapason1 == diapason2);
        }
        public override bool Equals(object obj)
        {
            if (obj is Diapason)
            {
                Diapason d = (Diapason)obj;
                return X == d.X && Y == d.Y;
            }
            return false;
        }
    }
}
