using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PersonLibrary;

namespace Lab12
{
    [Serializable]
    public class MyEnumerator<T> : IEnumerator<T>
    {
        private Node<T> _current;
        private BinaryTree<T> _tree;
        T IEnumerator<T>.Current
        {
            get
            {
                if (this.Current != null)
                    return _current._value;
                else
                    return default;
            }
        }
        public object Current
        {
            get { return _current._value; }
        }
        public MyEnumerator(BinaryTree<T> tree)
        {
            _tree = tree;
            _current = null;
        }
        public void Dispose()
        {
            _current = null;
        }
        public bool MoveNext()
        {
            if (this._tree.Count == 0)
                return false;

            if (_current == null)
                _current = _tree.FindMostLeft(_tree.Root);
            else
            {
                if (_current._right != null)
                    _current = _tree.FindMostLeft(_current._right);
                else
                {
                    while (_current._parent._right == _current)
                    {
                        _current = _current._parent;

                        if (_current._parent == null)
                        {
                            return false;
                        }
                    }
                    _current = _current._parent;
                }
            }
            return (_current != null);
        }
        public void Reset()
        {
            _current = _tree.Root;
        }
    }
}