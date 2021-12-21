#include <iostream>
#include <ctime>
using namespace std;

void print_arr(int arr[], int length)
{
	cout << "Печать массива" << endl;
	for (int i = 0; i < length; i++)
		cout << arr[i] << "; ";
}

void keep_removing(bool& keepRemovingFlag)
{
	bool checkIfCorrect = false;
	do
	{
		int temp;
		cout << "\nУдалить ещё элемент? (1/0) >";
		cin >> temp;

		if (temp == 1)
			checkIfCorrect = true;
		else if (temp == 0)
		{
			keepRemovingFlag = true;
			checkIfCorrect = true;
		}
	} while (!checkIfCorrect);
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	const int SIZE = 100;
	int arr[SIZE], length = 0;
	
	cout << "16. Реализовать с использованием массива очередь (первый пришёл, первый ушёл)," << "\n"
		<< "для чего организовать добавление, удаление элементов в массив и печать массива" << "\n"
		<< "после каждой операции." << "\n\n";

	// checking if a person is a dumbass
	do
	{
		cout << "Введите размер множества (положительное число, меньшее 100): ";
		cin >> length;
	} while (length < 0 || length > 99);	
	
	// add elements to arr
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << " элемент массива ";
		arr[i] = rand() % 1000;		
		cout << arr[i] << " пришёл" << endl;
	}

	bool keepRemovingFlag = false;
	while (length != 0 && !keepRemovingFlag)
	{
		int index;
		do
		{
			cout << "\nПод каким номером удалить элемент? >";
			cin >> index;
		} while (index < 0 || index > length);
		
		bool startRemoving = false;
		if (index == length)
		{
			index--;
			arr[index] = INT_MIN;
			startRemoving = true;
		}
		else
		{
			index--;
			for (int i = 0; i < length - 1; i++)
			{
				if (i == index)
				{
					cout << arr[i] << " ушёл" << endl;
					startRemoving = true;
				}
				if (startRemoving)
					arr[i] = arr[i + 1];
			}
		}
			
		if (startRemoving)
			length--;

		print_arr(arr, length);

		keep_removing(keepRemovingFlag);		
	}

	if (length == 0)
		cout << "Массив пуст" << endl;
}