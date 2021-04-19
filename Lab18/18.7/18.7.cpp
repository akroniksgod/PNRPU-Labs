#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    //Vector<int>vec(2,-1);   
    //cout << vec << endl;
    //Vector<double>* pvec = new Vector<double>(6, 2.625);
    //cout << *pvec << endl;    
    //pvec->~Vector();
    //Vector<float>*pvec2 = new Vector<float>(2, 10.5);
    //cout << *pvec2 << endl;
    //pvec2->~Vector();
    //Time prom(40, 23);
    //Vector<Time>* pvec3 = new Vector<Time>(2, prom);
    //cout << *pvec3 << endl;    
    Time a,b; int one, two;
    cout << "Первая пара (a)" << endl;
    one=a.GetMins();
    a.SetMins(one);
    one = a.GetSecs();
    a.SetSecs(one);
    cout << "Вторая пара (b)" << endl;
    two = b.GetMins();
    b.SetMins(two);
    two = b.GetSecs();
    b.SetSecs(two);
    cout << "sum " << a + b << endl;

    Vector<Time>A(5, a);
    cout <<"Вектор А: " <<A << endl;
    Vector<Time>B(3, b);
    cout << "Вектор B: " << B << endl;

    cout << "size A " << A() << endl
        << "size B " << B() << endl;

    B = A;
    cout << "\nВектор B после присвоения вектора A: " << B << endl;

    cout << "\nA[2]=" << A[2] << endl;

    B = A + a;
    cout << "\nA+a: " <<B;
    return 0;
}