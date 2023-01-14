using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PersonLibrary;

namespace Lab12
{
    [Serializable]
    public class BinaryTree<T> : IEnumerable<T>
    {
        static Random rnd = new Random();
        private Node<T> _root;
        private List<T> storage;
        public Node<T> Root
        {
            get { return _root; }
        }
        public int Count
        {
            get
            {
                Node<T> current = _root;
                return CountNodes(current);
            }
        }
        public BinaryTree()
        {
            _root = null;
            storage = new List<T>();
        }
        public BinaryTree(int capacity)
        {
            storage = new List<T>();
            if (capacity <= 0)
            {
                throw new Exception("Wrong parameter");
            }

            for (int i = 0; i < capacity; i++)
            {
                T val = (T)((IExecutable)ReturnPerson());
                this.Add(val);//default(T));
                //storage.Add(val);//default(T));
            }
        }
        public BinaryTree(BinaryTree<T> collectionToCopy)
        {
            if (storage == null)
                storage = new List<T>();

            foreach (var item in collectionToCopy.storage)
            {
                this.Add((T)((IExecutable)item).Clone());
            }

            /*foreach (var item in collectionToCopy)
            {
                this.Add((T)((IExecutable)item).Clone());
            }*/

            //this._root = collectionToCopy.CopyTree(collectionToCopy.Root);
            storage = collectionToCopy.storage.GetRange(0, collectionToCopy.Count);
        }
        private object ReturnPerson()
        {
            int choice = rnd.Next(1, 5);
            if (choice == 1)
            {
                Person p = new Person();
                return p.RandomCreate();
            }
            else if (choice == 2)
            {
                Schoolchild s = new Schoolchild();
                return s.RandomCreate();
            }
            else if (choice == 3)
            {
                Student s = new Student();
                return s.RandomCreate();
            }
            else if (choice == 4)
            {
                PartTimeStudent s = new PartTimeStudent();
                return s.RandomCreate();
            }
            return null;
        }
        private int CountNodes(Node<T> current)
        {
            if (current == null)
                return 0;
            return CountNodes(current._right) + CountNodes(current._left) + 1;
        }
        private void CreateRoot(T data)
        {
            Node<T> newItem = new Node<T>(data, null);
            if (_root == null)
            {
                _root = newItem;
            }
        }
        public void Add(T data)
        {
            storage.Add(data);
            int num = 0;
            _root = ToBalanceTree(storage.Count, ref num);
        }
        private Node<T> ToBalanceTree(int n, ref int iterator)
        {
            if (n == 0) 
                return null;

            T value = storage[iterator];
            iterator++;
            BinaryTree<T> tree = new BinaryTree<T>();
            tree.CreateRoot(value);
            tree.AddLeftTree(ToBalanceTree(n / 2, ref iterator));            
            tree.AddRightTree(ToBalanceTree(n - n / 2 - 1, ref iterator));
            return tree.Root;
        }
        private void AddLeftTree(Node<T> node)
        {
            this._root._left = node;
            if (node != null)
            {
                node._parent = this._root;
            }
        }
        private void AddRightTree(Node<T> node)
        {
            this._root._right = node; 
            if (node != null)
            {
                node._parent = this._root;
            }
        }
        public void Remove(int idToRemove)
        {
            CompareByAge comparer = new CompareByAge();
            BinaryTree<T> newTree = new BinaryTree<T>();

            foreach (var item in this)
            {
                if (((Person)((IExecutable)item)).Id == idToRemove)
                {
                    storage.Remove(item);
                }
            }

            foreach (var item in storage)
            {
                if ((((Person)(IExecutable)item)).Id.CompareTo(idToRemove) != 0)//comparer.Compare(item, val) != 0)
                    newTree.Add(item);
            }

            _root = newTree.Root;
        }
        public void Remove(T val)
        {
            CompareByAge comparer = new CompareByAge();
            BinaryTree<T> newTree = new BinaryTree<T>();
            storage.Remove(val);
            
            foreach (var item in storage)
            {
                if (comparer.Compare(item, val) != 0)
                    newTree.Add(item);
            }

            _root = newTree.Root;
        }
        public void Show()
        {
            if (_root == null)
            {
                Console.WriteLine("The tree is empty");
                return;
            }
            InOrder(_root);
            Console.WriteLine();
        }
        private void InOrder(Node<T> current)
        {
            if (current != null)
            {
                InOrder(current._left);
                Console.WriteLine("({0}) ", current._value.ToString());
                InOrder(current._right);
            }
        }
        internal Node<T> FindMostLeft(Node<T> start)
        {
            Node<T> node = start;
            while (true)
            {
                if (node._left != null)
                {
                    node = node._left;
                    continue;
                }
                break;
            }
            return node;
        }
        public IEnumerator<T> GetEnumerator()
        {
            return new MyEnumerator<T>(this);
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
        public bool Find(T key)
        {
            foreach (var item in this)
            {
                if (item is Person loopItem && key is Person keyItem)
                {
                    if (loopItem == keyItem)
                    {
                        Console.WriteLine("Element is found!\n");
                        return true;
                    }                        
                }
            }
            Console.WriteLine("Element is NOT found!\n");
            return false;
        }
        public BinaryTree<T> Clone()
        {
            return new BinaryTree<T>(this);
        }
        /*private Node<T> CopyTree(Node<T> node)
        {
            if (node == null)
                return null;
            
            Node<T> newNode = (Node<T>)node.Clone();
            //IExecutable pers = node._value as IExecutable;
            //Node<T> newNode = new Node<T>((IExecutable)pers.Clone(), node._parent);
            newNode._left = CopyTree(node._left);
            newNode._right = CopyTree(node._right);
            return newNode;
        }*/
        public BinaryTree<T> ShallowCopy()
        {
            return (BinaryTree<T>)this.MemberwiseClone();
        }
        public void Clear()
        {
            _root = RemoveAllElements(this);
        } 
        private Node<T> RemoveAllElements(BinaryTree<T> tree)
        {
            List<T> collectionForRemoving = new List<T>(storage);
            int length = tree.Count;
            foreach (var item in collectionForRemoving)
            {
                tree.Remove(item);
            }
            storage.RemoveRange(0,storage.Count);
            return null;
        }

        public int FindAndReturnIndex(int idToFind)
        {
            int index = 0;
            bool found = false;
            foreach (var item in this)
            {
                if (((Person)((IExecutable)item)).Id == idToFind)
                {
                    found = true;
                    break; 
                }
                index++;
            }

            if (found)
                return index;
            else
                return -1;
        }

        public virtual IExecutable this[int index]
        {
            get
            {
                if (index < this.Count)
                {
                    int counter = 0;
                    IEnumerator enumerator = this.GetEnumerator(); // получаем IEnumerator
                    while (enumerator.MoveNext())   // пока не будет возвращено false
                    {
                        if (index == counter)
                            return (IExecutable)enumerator.Current;
                        counter++;
                    }
                    return (IExecutable)this.Root._value;
                }
                return null;
            }
            set
            {
                var tree = this;
                var cur = this.FindMostLeft(this.Root);
                int i = 0;
                for (; i < index; i++)
                {
                    if (cur == null)
                    {
                        cur = this.FindMostLeft(this.Root);
                    }
                    else
                    {
                        if (cur._right != null)
                            cur = this.FindMostLeft(cur._right);
                        else
                        {
                            while (cur._parent._right == cur)
                            {
                                cur = cur._parent;

                                if (cur._parent == null)
                                {
                                    return;
                                }
                            }
                            cur = cur._parent;
                        }
                    }
                    //return (_current != null);
                }
                cur._value = (T)value;
            }
        }
    }    
}