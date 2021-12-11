#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	int i, j, k, n, temp, temp1;
	do
	{
		cout << "Введите основание треугольника (нечётное): ";
		cin >> n;
		cout << "\n";
	} while (n % 2 == 0);

	temp = n;
	for (i = 1; i <= temp; i++)
	{
		temp1 = i;
		for (j = 1; j <= n - (n / 2 + 1); j++)
		{
			cout << " ";
		}
		n = n - 2;
		for (i = 1; i <= temp1; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
