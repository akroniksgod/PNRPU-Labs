using System;
using System.Collections.Generic;
using System.Linq;
using Lab13;
using Lab12;
using PersonLibrary;

namespace Lab13
{
    public class Journal<T>
    {
        List<JournalEntry<T>> _journalEntries = new List<JournalEntry<T>>();
        class JournalEntry<T>
        {
            public string CollectionName
            {
                get; set;
            }
            public string EventDescription
            {
                get; set;
            }
            public T Value
            {
                get; set;
            }
            public MyNewCollection<T> CurrentCollection
            {
                get; set;
            }
            public JournalEntry(MyNewCollection<T> collection, CollectionHandlerEventArgs<T> args)
            {
                CollectionName = args.Name;
                EventDescription = args.Message;
                Value = args.Value;
                CurrentCollection = collection;
            }
            public override string ToString()
            {
                return $"{Value.ToString()} {EventDescription} in {CollectionName}";
            }
        }
        public void Add(MyNewCollection<T> collection, CollectionHandlerEventArgs<T> args)
        {
            _journalEntries.Add(new JournalEntry<T>(collection, args));
        }
        public string Show()
        {
            string res = "";
            foreach (var entry in _journalEntries)
            {
                res += entry.ToString() + '\n';
            }
            return res;
        }
        public void CollectionCountChanged(object source, CollectionHandlerEventArgs<T> evnt)
        {
            Add((MyNewCollection<T>)source, evnt);
        }
        public void CollectionReferenceChanged(object source, CollectionHandlerEventArgs<T> evnt)
        {
            Add((MyNewCollection<T>)source, evnt);
        }
    }
}
