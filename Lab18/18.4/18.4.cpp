#include <iostream>
#include "Pair.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Pair a, b,sum, razn;
	int tmp;
	cout << "Введите первую пару." << endl;
	tmp =a.GetFirst();
	a.SetFirst(tmp);
	tmp =a.GetSecond();
	a.SetSecond(tmp);
	cout << "\nВведите вторую пару."<< endl;
	tmp =b.GetFirst();
	b.SetFirst(tmp);
	tmp = b.GetSecond();
	b.SetSecond(tmp);
	cout << endl<<"Сумма: " << a + b << endl;
	Complex p(a, b);
	int res1=p.getReal(), res2=p.getImag();
	cout << "Комплексное число: ";
	p.ShowComplex();	
	cout << "\nРазность: " << a-b << endl;
}