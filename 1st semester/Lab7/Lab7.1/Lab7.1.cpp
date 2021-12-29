#include <iostream>
#include <cmath>
using namespace std;

void hours_to_mins(float h);
void hours_to_mins(int h);
void mins_to_hours(int m);

int main()
{
	setlocale(LC_ALL, "ru");
	int c;
	do
	{
		int mins;
		float hours;
		cout << "Выбрать:" << endl
			<< "1) Перевод часов в минуты;" << endl
			<< "2) Перевод минут в часы;" << endl
			<< "3) Выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			do
			{
				cout << "Введите время в часах: ";
				cin >> hours;
			} while (hours < 0);
			hours_to_mins(hours);
			break;
		case 2:
			do
			{
				cout << "Введите время в минутах: ";
				cin >> mins;
			} while (mins < 0);
			mins_to_hours(mins);
			break;
		case 3:
			break;
		default:
			cout << "Нужно выбрать 1 или 2!" << endl;
			break;
		}
	} while (c != 3);	
}

void hours_to_mins(float h)
{
	cout << "Время в минутах: " << h * 60 << " минут(ы)" << endl;
}

void hours_to_mins(int h)
{
	cout << "Время в минутах: " << h * 60 << " минут(ы)" << endl;
}

void mins_to_hours(int m)
{
	if (m % 60 == 0)
		cout << "Время в часах: " << m / 60 << " часа(ов)" << endl;
	else
		cout << "Время в часах: " << m / 60 << " часа(ов)"
			<< " " << m % 60 << " минут(ы)" << endl;
}
