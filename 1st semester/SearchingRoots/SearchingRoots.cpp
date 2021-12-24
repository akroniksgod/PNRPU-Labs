#include <iostream> 
#include <cmath>
using namespace std;

const double EPS = 1e-6;

double f(double x)
{
	return (cos(pow(1 - 0.3 * (pow(x, 3)), 0.5)));
}

void Bisection()
{
	double a = 0, b = 1, x = 0;
	while (fabs(b - a) > EPS)
	{
		x = (a + b) / 2;
		if ((f(a) * f(x)) <= 0)
			b = x;
		else
			a = x;
	}
	cout << "Результат: " << x << endl;
}

double df(double x)
{
	return (-1 / (pow(1 - pow(x, 2), 0.5)) + (0.9 * pow(x, 2)) / (2 * pow(1 - 0.3 * pow(x, 3), 0.5)));
}

void NewtonsMethod()
{
	double a = 0, b = 1, xCurr, xPrev = 0;
	xCurr = (a + b) / 2;
	do
	{
		xPrev = xCurr;
		xCurr = xCurr - f(xCurr) / df(xCurr);
	} while (fabs(xPrev - xCurr) > EPS);
	cout << "Результат: " << xPrev << endl;
}

void FixedPointIteration()
{
	double a = 0, b = 1, xPrev = 0;
	double xCurr = (a + b) / 2;
	do
	{
		xPrev = xCurr;
		xCurr = f(xPrev);
	} while (fabs(xPrev - xCurr) >= EPS);
	cout << "Результат: " << xCurr << endl;
}

int main()
{	
	setlocale(LC_ALL, "Ru");
	bool exit = false;
	do
	{
		int choice;
		cout << "Выберете" << endl
			<< "1. Метод половинного деления" << endl
			<< "2. Метод касательных (Ньютона)" << endl
			<< "3. Метод итераций" << endl
			<< "4. Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: Bisection(); break;
		case 2: NewtonsMethod(); break;
		case 3: FixedPointIteration(); break;
		case 4: exit = true; break;
		default:
			cout << "Неверный ввод" << endl;
			continue;
			break;
		}
		cout << endl;
	} while (!exit);	
}