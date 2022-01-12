using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part3
{
    public class Id
    {
        public int _number;
        public Id(int n)
        {
            _number = n;
        }
        public override string ToString()
        {
            return _number.ToString();
        }
    }
}
