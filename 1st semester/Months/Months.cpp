#include <iostream>
using namespace std;

enum Months
{
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	June,
	July,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
};

int main()
{
	setlocale(LC_ALL, "Ru");
	int mon;
	cout << "Введите цифру месяца: ";
	cin >> mon;
	switch (mon)
	{
	case Jan:
		cout << "Январь" << endl;
	case Feb:
		cout << "Февраль" << endl;
	case Mar:
		cout << "Март" << endl;
	case Apr:
		cout << "Апрель" << endl;
	case May:
		cout << "Май" << endl;
	case June:
		cout << "Июнь" << endl;
	case July:
		cout << "Июль" << endl;
	case Aug:
		cout << "Август" << endl;
	case Sep:
		cout << "Сентябрь" << endl;
	case Oct:
		cout << "Октябрь" << endl;
	case Nov:
		cout << "Ноябрь" << endl;
	case Dec:
		cout << "Декабрь" << "\n";
		break;
	default:
		cout << "Нет такого месяца" << endl;
		break;
	}
}