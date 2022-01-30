using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part1
{
    public interface IExecutable
    {
        object RandomCreate();
        object Clone();
    }
}
