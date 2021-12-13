#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int z, s, dollar = 0, temp = 0; //z- зарплата, s - стаж
	
	cout << "Введите зарплату в рублях: ";
	cin >> z;
	
	cout << "Введите стаж работы: ";
	cin >> s;
	if (s <= 2)
		temp = 1;
	if (s == 3 || s == 4)
		temp = 2;
	if (s >= 5 && s <= 7)
		temp = 3;
	if (s >= 8 && s <= 70)
		temp = 4;

	switch (temp)
	{
	case 1:
		dollar = z * 0.5 * 0.012;
		cout << "Выплаты на больничном составят " << z * 0.5 << " руб." << "или " << dollar << "$" << " \n";
		break;
	case 2:
		dollar = z * 0.6 * 0.012;
		cout << "Выплаты на больничном составят " << z * 0.6 << " руб." << "или " << dollar << "$" << " \n";
		break;
	case 3:
		dollar = z * 0.8 * 0.012;
		cout << "Выплаты на больничном составят " << z * 0.8 << " руб." << "или " << dollar << "$" << " \n";
		break;
	case 4:
		dollar = z * 0.012;
		cout << "Выплаты на больничном составят " << z << " руб. " << "или " << dollar << "$" << " \n";
		break;

	default:
		cout << "err" << endl;
		break;
	}
}