#include <iostream>
using namespace std;
//Triangle
int main()
{
	setlocale(LC_ALL, "Ru");
	int n, i, j, z;
	cout << "Введите N: ";
	cin >> n;
	for (i = 1; i <= n + 1; i++)
	{
		z = i;
		for (j = 1; j <= n - z + 1; j++)
			cout << " ";

		for (j = 1; j < z; j++)
			cout << "*";

		cout << endl;
	}
}
