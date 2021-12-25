#include <iostream>
#include <cmath>
using namespace std;

double recur(double n, double sum);

int main()
{
	setlocale(LC_ALL, "ru");
	double n, s = 0;
	do
	{
		cout << "Введите количество шагов: ";
		cin >> n;
	} while (n < 1 || n > 100);	
	cout << recur(n, s);
}

double recur(double n, double sum)
{
	double f, y;
	if (n == 1)
		return pow(12, 0.5) * (1 + sum);

	if (n >= 2)
	{
		f = pow((-1), n - 1) * (1 / ((2 * n - 1) * pow(3, n - 1)));
		sum += f;
		return recur(n - 1, sum);
	}
}
