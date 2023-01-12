using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using PersonLibrary;
using Lab14;

namespace UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int cap = 5;
            City city = new City(cap);
            EducationaLInstitution institution = new EducationaLInstitution(cap);

            //City city = new City(5);
            //EducationaLInstitution institution = new EducationaLInstitution(city);
            
            Person p = new Person();
            p = (Person)p.RandomCreate();
            institution.Add(p);
            Person per = (Person)p.RandomCreate();
            institution.Add(p);
            institution.Show();
            institution.Remove(p);            

            city.Add(institution);
            city.Show();
            city.Remove(institution);            
        }

        [TestMethod]
        public void TestMethod2()
        {
            City city = new City();
            EducationaLInstitution institution = new EducationaLInstitution();
        }

        [TestMethod]
        public void TestMethod3()
        {
            City city = new City(15);
            City Perm = new City(city);
            EducationaLInstitution institution = new EducationaLInstitution(50);
        }
    }
}
