#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	int N = 0, S = 0, x = 0;
	while (N < 1)
	{
		cout << "Введите число:";
		cin >> N;
	}

	x = N;
	while (N > 0)
	{
		S += N % 10;
		N = N / 10;
	}
	cout << "Введённое число: " << x << "; " << " Результат:" << S;
}