#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(const int N, int* arr);
void SelectionSort(const int N, int* arr);
void InsertionSort(const int N, int* arr);
void FillArrManually(int* arr, const int size);
void FillArrRandomly(int* arr, const int size);
void PrintArr(int* arr, const int size);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int d;
	const int n = 5;
	int arr[n];
	cout << "1. Заполнить массив вручную\n"
		<< "2. Заполнить массив через ДСЧ\n";
	do
	{		
		cin >> d;
		switch (d)
		{
		case 1: FillArrManually(arr, n); break;
		case 2: 
		{
			FillArrRandomly(arr, n);
			PrintArr(arr, n);
			break;
		}
		default:
			cout << "\nНеверный выбор!" << endl;
			break;
		}
	} while (d < 1 || d > 2);
	

	cout << "\nОтсортировать массив: " << endl
		<< "1) методом обмена (пузырька) " << endl
		<< "2) методом выбора " << endl
		<< "3) методом вставки" << endl;
	do
	{		
		cin >> d;
		switch (d)
		{
		case 1: BubbleSort(n, arr);	break;
		case 2:	SelectionSort(n, arr); break;
		case 3: InsertionSort(n, arr); break;
		default:
			cout << "\nНеверный выбор!" << endl;
			break;
		}
	} while (d < 1 || d > 3);	

	PrintArr(arr, n);
}

void BubbleSort(const int N, int* arr)
{
	int temp;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(const int N, int* arr)
{
	int min, temp;
	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] <= arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void InsertionSort(const int N, int* arr)
{
	int temp;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
}

void FillArrManually(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива: ";
		cin >> arr[i];
		cout << endl;
	}
	cout << endl;
}

void FillArrRandomly(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void PrintArr(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "; ";
	}
	cout << endl;
}