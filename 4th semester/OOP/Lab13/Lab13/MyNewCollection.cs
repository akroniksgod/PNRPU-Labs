using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab12;
using PersonLibrary;

namespace Lab13
{
    public delegate void CollectionHandler(object source, CollectionHandlerEventArgs<IExecutable> args);

    public class CollectionHandlerEventArgs<T> : EventArgs
    {
        public string Name { get; }
        public string Message { get; }
        public T Value { get; }
        public CollectionHandlerEventArgs(string name, string str, T value)
        {
            Name = name;
            Message = str;
            Value = value;
        }
    }
    public class MyNewCollection<T> : BinaryTree<IExecutable>
    {
        public event CollectionHandler CollectionCountChanged;
        public event CollectionHandler CollectionReferenceChanged;        
        public string Name
        {
            get; set;
        }
        public virtual void OnCollectionCountChanged(object source, CollectionHandlerEventArgs<IExecutable> args)
        {
            if (CollectionCountChanged != null)
                CollectionCountChanged(source, args);
        }
        public virtual void OnCollectionReferenceChanged(object source, CollectionHandlerEventArgs<IExecutable> args)
        {
            if (CollectionReferenceChanged != null)
                CollectionReferenceChanged(source, args);
        }
        public override void Remove(IExecutable val)
        {
            OnCollectionCountChanged(this, new CollectionHandlerEventArgs<IExecutable>(this.Name, "deleted", val));
            base.Remove(val);             
        }
        public override void Add(IExecutable p)
        {
            OnCollectionCountChanged(this, new CollectionHandlerEventArgs<IExecutable>(this.Name, "added", p));
            base.Add(p);
        }
        public override IExecutable this[int index]
        {
            get { return base[index]; }
            set
            { 
                OnCollectionReferenceChanged(this, new CollectionHandlerEventArgs<IExecutable>(this.Name, "changed", this[index]));
                base[index] = value;
            }
        }
    }
}