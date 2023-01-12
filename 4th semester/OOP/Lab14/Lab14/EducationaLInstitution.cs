using System;
using System.Collections.Generic;
using System.Linq;
using PersonLibrary;

namespace Lab14
{
    public class EducationaLInstitution
    {
        //public List<Schoolchild> students;
        public Dictionary<int, Person> _people;
        static Random rnd = new Random();
        public EducationaLInstitution()
        {
            _people = new Dictionary<int, Person>();
        }
        public EducationaLInstitution(int count)
        {
            _people = new Dictionary<int, Person>();
            for (int i = 0; i < count; i++)
            {
                int choice = rnd.Next(1, 5);
                if (choice == 1)
                {
                    Person p = new Person();
                    p = (Person)p.RandomCreate();
                    _people.Add(i, p);
                }
                else if (choice == 2)
                {
                    Schoolchild s = new Schoolchild();
                    s = (Schoolchild)s.RandomCreate();
                    _people.Add(i, s);
                }
                else if (choice == 3)
                {
                    Student s = new Student();
                    s = (Student)s.RandomCreate();
                    _people.Add(i, s);
                }
                else if (choice == 4)
                {
                    PartTimeStudent s = new PartTimeStudent();
                    s = (PartTimeStudent)s.RandomCreate();
                    _people.Add(i, s);
                }
            }
        }
        public EducationaLInstitution(EducationaLInstitution institution)
        {
            _people = new Dictionary<int, Person>();
            int index = 0;
            foreach (var item in institution._people.Values)
            {
                if (item is PartTimeStudent)
                    _people.Add(index, (PartTimeStudent)item.Clone());

                else if (item is Student)
                    _people.Add(index, (Student)item.Clone());

                else if (item is Schoolchild)
                    _people.Add(index, (Schoolchild)item.Clone());

                else
                    _people.Add(index, (Person)item.Clone());
                index++;
            }
        }
        public void Add(Person item)
        {
            int index = _people.Count;
            _people.Add(index, item);
        }
        public void Remove(Person item)
        {
            if (_people.ContainsValue(item))
            {
                int index = 0;
                for (int i = 0; i < _people.Count; i++)
                {
                    if (item == _people[i])
                    {
                        index = i;
                        break;
                    }                        
                }
                _people.Remove(index);
            }                
        }
        public void Show()
        {
            Console.WriteLine("\nУчебное учереждение");
            foreach (var item in _people)
            {
                Console.WriteLine(item.Value.ToString());
            }
            Console.WriteLine();
        }
    }
}
