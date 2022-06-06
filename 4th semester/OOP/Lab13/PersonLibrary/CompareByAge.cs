using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonLibrary
{
    public class CompareByAge : IComparer
    {
        public int Compare(object x, object y)
        {
            if (x == null || y == null)
                return 0;

            Person p1 = (Person)x,
                p2 = (Person)y;
            if (p1.Age < p2.Age)
                return -1;
            else if (p1.Age == p2.Age)
                return 0;
            return 1;
        }
    }
}
