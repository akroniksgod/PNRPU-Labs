using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonLibrary
{
    public class Id
    {
        public int _number;

        public int Number
        {
            get { return _number; }
            set { _number = value; }
        }
        public Id()
        {
            Number = 0;
        }
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
