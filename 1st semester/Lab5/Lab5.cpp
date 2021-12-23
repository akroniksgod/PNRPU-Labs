#include <iostream>
#include <algorithm>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

const int SIZE = 5;

void fill_matrix(int arr[][SIZE]);
void print_matrix(int arr[][SIZE]);
void sort_matrix(int arr[][SIZE]);
bool check_secondary_diagonal(int arr[][SIZE]);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	
	int arr[SIZE][SIZE];
	cout << "Изначальная матрица" << endl;
	fill_matrix(arr);
	print_matrix(arr);
	
	sort_matrix(arr);
	cout << "Отсортированная по столбцам матрица" << endl;
	print_matrix(arr);

	if (!check_secondary_diagonal(arr))
	{
		bool impossibleToSort = false;
		int comparator = arr[0][SIZE - 1];
		for (int i = 1; i < SIZE && !impossibleToSort; i++)
		{
			for (int j = SIZE - 1 - i; j >= 0 && !impossibleToSort; j--)
			{
				int l = i;
				if (arr[i][j] <= comparator)
				{
					int m = SIZE - 1;
					while (arr[l][j] < comparator && !impossibleToSort)
					{
						if (arr[m][j] > comparator)
						{
							int temp2 = arr[m - 1][j];
							if (temp2 < comparator)
							{
								std::swap(arr[m][j], arr[l][j]);
								break;
							}
						}
						else
							impossibleToSort = true;

						if (--m == l)
							break;
					}
				}
				else
				{
					int m = 0;
					while (arr[l][j] > comparator)
					{
						if (arr[m][j] > comparator)
						{
							std::swap(arr[m][j], arr[l][j]);
							break;
						}
						else
							m++;

						if (m == l)
							break;
					}
				}
				comparator = arr[i][j];
				print_matrix(arr);
				break;
			}
		}

		if (impossibleToSort)
			cout << "Невозможно отсортировать побочную диагональ(" << endl;
		else
			cout << "Побочная диагональ отсортирована)" << endl;
	}		
	else
		cout << "Побочная диагональ отсортирована)" << endl;
}

void fill_matrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			int temp = rand() % 100;
			arr[i][j] = temp;
		}
	}
}

void print_matrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << arr[i][j] << ";\t";

		cout << endl;
	}
	cout << endl;
}

void sort_matrix(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		int temp[SIZE], k = 0;
		for (int j = 0; j < SIZE; j++)
			temp[k++] = arr[j][i];

		std::sort(temp, temp + k);

		k = 0;
		for (int j = 0; j < SIZE; j++)
			arr[j][i] = temp[k++];
	}
}

bool check_secondary_diagonal(int arr[][SIZE])
{
	bool isFine = true;
	int comparator = arr[0][SIZE - 1];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1 - i; j >= 0; j--)
		{
			if (arr[i][j] < comparator)
				return false;
			else
				comparator = arr[i][j];
			break;
		}
	}
	return true;
}