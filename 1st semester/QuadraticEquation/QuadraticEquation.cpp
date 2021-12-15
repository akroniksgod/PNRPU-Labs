#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	int count;
	double a, b, c, d, x1, x2;
	do
	{
		cout << "Введите количество уравнений: ";
		cin >> count;
	} while (count < 1);
	
	for (int i = 1; i <= count; i++)
	{
		cout << "Введите коэффиценты уравнения a,b,c:";
		cin >> a >> b >> c;
		if (a != 0)
		{
			d = pow(b, 2) - 4 * a * c;
			if (d >= 0)
			{
				x1 = (-1 * b - pow(d, 0.5)) / (2 * a);
				x2 = (-1 * b + pow(d, 0.5)) / (2 * a);
								
			}
			else
				cout << "Нет действительных корней" << endl;
		}
		else if (b != 0)
		{
			x1 = x2 = -c / b;
			cout << "Решения уравнения: x1= " << x1 << " и x2= " << x2 << ";\n";
		}		
		else if (c == 0)
			cout << "x - любое число\n";
	}
}