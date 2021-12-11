#include <iostream>
#include <clocale>
#include <bitset>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k, count = 0, zeros;
	cout << "Введите N и K" << " \n";
	cin >> n >> k;
	for (int i = 1; i < n + 1; i++)
	{
		zeros = 0;
		cout << i << "=";
		cout << bitset<(8)>(i) << "; ";
		int b = i;
		while (b != 0)
		{
			zeros += !(b & 1);
			b >>= 1;
		}
		if (zeros == k)
			count++;
	}
	cout << endl << count << endl;
}
