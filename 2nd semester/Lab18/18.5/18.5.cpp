#include <iostream>
#include "Abstract.h"
#include "Pair.h"
#include"Complex.h"
#include "Vector.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	Pair a, b;
	int tmp;
	cout << "Введите первую пару." << endl;
	//cin >> a;
	tmp = a.GetFirst();	 
	a.SetFirst(tmp);
	tmp = a.GetSecond();
	a.SetSecond(tmp);
	cout << "\nВведите вторую пару." << endl;
	//cin >> b;
	tmp = b.GetFirst();
	b.SetFirst(tmp);
	tmp = b.GetSecond();
	b.SetSecond(tmp);
	cout << endl << "Сумма: " << a + b << endl;
	Complex p(a, b); //создание объекта класса Complex	
	cout << "\nРазность: " << a - b << endl;
	Abstract *ptr = &a;
	ptr->Show(); //вывод в консоль первой введённой пары
	ptr = &b;
	ptr->Show(); //вывод в консоль второй введённой пары
	ptr = &p;
	cout << "Комплексное число: ";
	ptr->Show(); //вывод в консоль объекта класса Complex
	Vector vec(3); 
	vec.push(ptr); //добавление обекта класса Complex в вектор
	cout << "\nВектор: " << vec;
	return 0;
}