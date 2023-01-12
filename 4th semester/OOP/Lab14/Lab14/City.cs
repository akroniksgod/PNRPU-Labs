using System;
using System.Collections.Generic;
using System.Linq;
using PersonLibrary;

namespace Lab14
{
    public class City
    {
        public Stack<EducationaLInstitution> _institutions;
        static Random rnd = new Random();
        public City()
        {
            _institutions = new Stack<EducationaLInstitution>();
        }
        public City(int count)
        {
            _institutions = new Stack<EducationaLInstitution>();
            for (int i = 0; i < count; i++)
            {
                EducationaLInstitution institution = new EducationaLInstitution();                
                
                for (int j = 0; j < 3; j++)
                {
                    int choice = rnd.Next(1, 5);
                    if (choice == 1)
                    {
                        Person p = new Person();
                        p = (Person)p.RandomCreate();
                        institution.Add(p);
                    }
                    else if (choice == 2)
                    {
                        Schoolchild s = new Schoolchild();
                        s = (Schoolchild)s.RandomCreate();
                        institution.Add(s);
                    }
                    else if (choice == 3)
                    {
                        Student s = new Student();
                        s = (Student)s.RandomCreate();
                        institution.Add(s);
                    }
                    else if (choice == 4)
                    {
                        PartTimeStudent s = new PartTimeStudent();
                        s = (PartTimeStudent)s.RandomCreate();
                        institution.Add(s);
                    }                    
                }
                _institutions.Push(institution);
            }
        }
        public City(City city)
        {
            _institutions = new Stack<EducationaLInstitution>();
            foreach (var item in city._institutions)
            {
                _institutions.Push(new EducationaLInstitution(item));
            }
        }
        public void Add(EducationaLInstitution item)
        {
            _institutions.Push(item);
        }
        public void Remove(EducationaLInstitution item)
        {
            Stack<EducationaLInstitution> copy = new Stack<EducationaLInstitution>();
            for (int i = 0; i < this._institutions.Count; i++)
            {
                if (_institutions.Peek() != item)
                    copy.Push(_institutions.Pop());
            }
            _institutions = new Stack<EducationaLInstitution>(copy);
        }
        public void Show()
        {
            Console.WriteLine("Город");
            foreach (var item in _institutions)
            {
                //Console.WriteLine(item.);
                item.Show();
            }
        }
    }
}
