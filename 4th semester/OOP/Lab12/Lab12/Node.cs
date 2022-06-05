using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PersonLibrary;

namespace Lab12
{
    public class Node<T> where T : IExecutable
    {
        public Node<T> _left, _right, _parent;
        public T _value;
        public Node(T data, Node<T> parent)
        {
            _value = data;
            _left = null;
            _right = null;
            _parent = parent;
        }
    }
}
