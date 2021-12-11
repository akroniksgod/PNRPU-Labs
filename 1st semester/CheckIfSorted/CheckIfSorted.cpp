#include <iostream>
using namespace std;

//ОПРЕДЕЛИТЬ, ЯВЛЯЕТСЯ ЛИ СТРОКА ОТСОРТИРОВАННОЙ ПО ВОЗРОСТАНИЮ
int main()
{
	setlocale(LC_ALL, "Ru");
	int a, b = 0;	
	cin >> a;

	bool flag = true;
	if (a != 0)
	{
		cin >> b;
		if (b != 0)
		{
			while ((b != 0) && (a != b) && flag)
			{
				flag = flag && (a < b);
				if (flag)
				{
					a = b;
					cin >> b;
				}

			}
			if (flag)
				cout << "Строка отсортирована\n";
			else
				cout << "Строка не отсортирована\n";
		}
		else
			cout << "Последовательность не существует\n";
	}
	else
		cout << "Последовательность не существует\n";

}
