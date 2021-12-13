#include <iostream> 
using namespace std;

//Пустой квадрат
int main()
{	
	setlocale(LC_ALL, "Rus");
	int n;
	do
	{
		cout << "Введите сторону квадрата (больше 2): ";
		cin >> n;
	} while (n < 3);
	
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << "*" << " ";

	cout << endl;

	for (int i = 1; i < n - 1; i++)
	{
		cout << "*";

		for (int j = 1; j <= n + (n - 3); j++)
			cout << " ";

		cout << "*" << endl;
	}

	for (int i = 1; i <= n; i++)
		cout << "*" << " ";
}