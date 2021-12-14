#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	int N = 0, x = 0, z = 0;
	bool foundDigit = false;
	
	do
	{
		cout << "Введите цифру Z: ";
		cin >> z;
	} while (z < -1 || z > 10);
	
	cout << "Введите число: ";
	cin >> N;

	if (N < 0)
		N *= -1;

	while (N > 0 && !foundDigit)
	{
		x = N % 10;
		if (x == z)
			foundDigit = true;
		N /= 10;
	}

	if (foundDigit)
		cout << "Такая цифра есть в числе\n";
	else
		cout << "Такой цифры нет в числе\n";
}
