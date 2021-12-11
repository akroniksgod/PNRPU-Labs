#include <iostream> 
using namespace std;

//РАНЬШЕ ПОЛОЖИТЕЛЬНОЕ ИЛИ ОТРИЦАТЕЛЬНОЕ
int main()
{
	int n, i, a;
	bool flag = false;
	setlocale(LC_ALL, "Ru");
	cout << "Введите кол-во элементов в последовательности: ";
	cin >> n;
	i = 1;
	while (!flag && (i <= n))
	{
		cout << "Введите последовательность: ";
		cin >> a;
		if (a == 0)
			i++;
		else
			flag = true;
	}
	if (flag)
	{
		if (a < 0)
			cout << "Раньше встречается отрицательное число\n";
		else
			cout << "Раньше встречается положительное число\n";
	}
	else
		cout << "Все элементы последовательности равны нулю\n";
}