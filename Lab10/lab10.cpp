#include <iostream>
#include <string>
using namespace std;
void FillArr(string* arr, int rows);
void ShowArr(string* arr, int rows);
void ChangeArr(string*& arr, int& rows);
int main()
{
	system("chcp 1251>nul");
	setlocale(LC_ALL, "ru");
	int rows = -1;
	while (rows < 0) {
		cout << "Введите количество строк: ";
		cin >> rows;
	}
	string* arr = new string[rows];
	FillArr(arr, rows);
	ShowArr(arr, rows);
	ChangeArr(arr, rows);
	cout << "\n\n";
	ShowArr(arr, rows);
	delete[] arr;
}
void FillArr(string* arr, int rows)
{
	while (cin.get() != '\n');
	for (int i = 0; i < rows; i++) {
		cout << "Введите строку: ";
		getline(cin, arr[i]);
	}
	cout << endl;
}
void ShowArr(string* arr, int rows)
{
	cout << "Вывод массива: " << endl;
	for (int i = 0; i < rows; i++) {
		cout << arr[i] << endl;
	}
	cout << "---------------------";
}
void ChangeArr(string*& arr, int& rows)
{
	string* tmp = new string[rows - 1];
	string min = arr[0];
	int min1 = arr[0].length(), ind = 0;
	for (int i = 0; i < rows; i++) {
		if (arr[i].length() < min.length()) {
			min = arr[i];
			min1 = arr[i].length();
			ind = i;
		}
	}
	for (int i = 0; i < ind; i++) {
		tmp[i] = arr[i];
	}
	for (int i = ind; i < rows - 1; i++) {
		tmp[i] = arr[i + 1];
	}
	delete[] arr;
	rows--;
	arr = tmp;
}
