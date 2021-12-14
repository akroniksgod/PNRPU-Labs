#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int z, s, temp = 0; //z- зарплата, s - стаж, k - курс доллара
	double dollar = 0;
	const double k = 0.012;
	cout << "Введите зарплату в рублях: ";
	cin >> z;
	cout << "Введите стаж работы: ";
	cin >> s;
	
	if (s <= 2)
		temp = 1;

	if ((s == 3) || (s == 4))
		temp = 2;

	if ((s >= 5) && (s <= 7))
		temp = 3;

	if ((s >= 8) && (s <= 70))
		temp = 4;

	switch (temp)
	{
	case 1:
		dollar = z * 0.5 * k;
		cout << "Выплаты на больничном составят " << z * 0.5 << "руб." << "или " << dollar << "$" << endl;
		break;
	case 2:
		dollar = z * 0.6 * k;
		cout << "Выплаты на больничном составят " << z * 0.6 << "руб." << "или " << dollar << "$" << endl;
		break;
	case 3:
		dollar = z * 0.8 * k;
		cout << "Выплаты на больничном составят " << z * 0.8 << "руб." << "или " << dollar << "$" << endl;
		break;
	case 4:
		dollar = z * k;
		cout << "Выплаты на больничном составят " << z << "руб. " << "или " << dollar << "$" << endl;
		break;
	default:
		cout << "Err" << endl;
		break;
	}
}
