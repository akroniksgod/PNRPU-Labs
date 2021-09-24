#include<iostream>
#include<cmath>
using namespace std;
class Check {
	double first;//левая граница
	double second;//правая граница	
public:
	Check() //конструктур для объекта без параметров
	{
	}
	Check(double leftvalue, double rightvalue)
	{
		first = leftvalue;
		second = rightvalue;
	}	
	double GetLeft()
	{
		double left;
		cout << "Введите левую границу >";
		cin >> left;
		return left;
	}
	double GetRight(double left)
	{
		double right;
		cout << "\nВведите правую границу >";
		cin >> right;
		if (right < left) {
			while (right < left) {
				cout << "\nВведите правую границу корректно >";
				cin >> right;
			}
		}
		return right;
	}
	void SetLeft(const double value)
	{
		first = value;
	}
	void SetRight(const double value)
	{
		second = value;
	}
	bool rangecheck(double x)
	{
		if (x >= first && x <= second) {
			return true;
		}
		else
			return false;
	}
};
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Поле first - дробное число, левая граница диапазона, поле second - дробное целое число, правая" << endl
		<< "граница диапазона. Реализовать метод rangecheck(double x) - проверку принадлежности" << endl
		<< "заданного числа x на принадлежность диапазону [first; second]" << "\n\n\n";
	Check One;
	double left, right, x;	
	left = One.GetLeft();//геттор для левой границы		
	right = One.GetRight(left);//геттор для правой границы
	One.SetLeft(left);//сеттор для левой границы
	One.SetRight(right);//сеттор для левой границы
	cout << "\nВведите число для проверки вхождения в отрезок >";	
	cin >> x;
	Check Second(left, right);
	int method;
	cout << "\nРеализовать через: " << endl
		<< "\tОбычное выделение памяти:" << endl
		<< "\t  1) Инициализация через сеттор;" << endl
		<< "\t  2) Инициализация через конструктор;" << endl
		<< "\tМассив:" << endl
		<< "\t  3) Статический;" << endl
		<< "\t  4) Динамический;" << endl
		<< ">";
	cin >> method;	
	switch (method) {		
	case 1:
		cout << "\nРеализация через сетторы: ";
		One.rangecheck(x) ? cout << "\tВХОДИТ В ОТРЕЗОК" : cout << "\tНЕ ВХОДИТ В ОТРЕЗОК";
		break;
	case 2:
		cout << "\nРеализация через конструктор: ";
		//объект second для реализации через конструктор	
		Second.rangecheck(x) ? cout << "\tВХОДИТ В ОТРЕЗОК" : cout << "\tНЕ ВХОДИТ В ОТРЕЗОК";
		break;
	case 3:
		cout << "\nРеализация через сетторы в статическом массиве: ";
		Check Arr[1];
		Arr[0].SetLeft(left);		
		Arr[0].SetRight(right);		
		Arr[0].rangecheck(x) ? cout << "\tВХОДИТ В ОТРЕЗОК" : cout << "\tНЕ ВХОДИТ В ОТРЕЗОК";		
		break;	
	}
	if (method == 4) {
		cout << "\nРеализация через сетторы в динамическом массиве: ";
		int n = 1;
		Check* Arr1 = new Check[n];		
		for (int i = 0; i < n; i++) {
			Arr1[i].SetLeft(left);
			Arr1[i].SetRight(right);
			Arr1[i].rangecheck(x) ? cout << "\tВХОДИТ В ОТРЕЗОК" : cout << "\tНЕ ВХОДИТ В ОТРЕЗОК";
		}
		delete[] Arr1;
	}
	return 0;
}