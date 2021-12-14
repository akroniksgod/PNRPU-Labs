#include <iostream> 
using namespace std;

//ПОИСК МАКСИМУМА И МИНИМУМА
int main()
{
	setlocale(LC_ALL, "Ru");
	int max, min, maxNumber = 1, sumMax = 1, count, a, minNumber = 1, sumMin = 1; 	
	
	cout << "Введите число N целых чисел: ";
	cin >> count;
	cout << "Введите число последовательности: ";
	cin >> max;
	
	min = max;
	for (int i = 2; i <= count; i++)
	{
		cout << "Введите число последовательности: ";
		cin >> a;
		if (a > max)
		{
			max = a;
			maxNumber = i;
			sumMax = 1;
		}
		else if (a == max)
			sumMax++;

		if (a < min)
		{
			min = a;
			minNumber = i;
			sumMin = 1;
		}
		else if (a == min)
			sumMin++;
	}

	if (max == min)
		cout << "\nВ множестве только одно число\n";
	else
	{
		cout << "\nМаксимальное значение: " << max << endl << "Номер максимума: " << maxNumber << endl 
			<< "Количество данных максимумов: " << sumMax << "\n";
		cout << "\nМинимальное значение: " << min << endl << "Номер минимума: " << minNumber << endl 
			<< "Количество данных минимумов: " << sumMin << "\n";
	}
}