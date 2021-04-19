#include "Number.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int method;
	cout << "\nРеализовать через: " << endl
		<< "\tОбычное выделение памяти:" << endl
		<< "\t  1) Инициализация через сеттор;" << endl
		<< "\t  2) Инициализация через конструктор;" << endl
		<< "\t  3) Инициализация через конструктор копирования;" << endl
		<< ">";
	cin >> method;
	if (method == 1)
	{
		Number first;
		float key = 0;
		int Por = 0;
		float mantissa = 0;
		key = first.GetStroka();
		first.SetStroka(key); //ввод числа
		Por = first.GetPoryadok(key);
		first.SetPoryadok(Por);//получение порядка
		mantissa = first.GetMant(key);
		first.SetMant(mantissa);//получение мантиссы	
		first.Show(); //вывод на экран
	}
	else if (method == 2) {
		float key;
		int Por = 0;
		float mantissa = 0;
		cout << "Введите число (если дробное, то через точку) >";
		cin >> key;
		Number Second(key, Por, mantissa);		
	}
	else if (method == 3) {
		float key;
		int Por = 0;
		float mantissa = 0;
		cout << "Введите число (если дробное, то через точку) >";
		cin >> key;
		cout << "\nThird2"<< endl;
		Number Third2(key, Por, mantissa);
		Number Third(Third2);
		cout << "\nБыло скопированно в Third"<< endl;
		Third.Show();
	}
}