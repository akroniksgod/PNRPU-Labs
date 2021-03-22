#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void MergeSort(vector<int>& arr, int left, int right, int kol);
void Merging(vector<int>& arr, int begin, int end, int kol);
void ShowArr(vector<int>arr, int kol);
vector<int> EstesMergeSort(vector<int>& arr, int kol, vector<int>& resultvec);
void PolyphaseMergeSort(vector<int>& arr, int kol);
void Fib(int& size1, int& size2, vector<int>& arr);
void PrintSeries(vector<vector<int>> series);
void InsertionSort(vector<int>& newSerie);
void Transition(vector<vector<int>>& min, vector<vector<int>>& max, vector<vector<int>>& nullel);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");
	int kol = -1;
	while (kol < 1) {
		cout << "Введите количество элементов в массиве >";
		cin >> kol;
	}
	vector<int>arr(kol);
	for (int i = 0; i < kol; i++) {
		arr[i] = rand() % 100;
	}
	cout << "\nИзначальный массив: ";
	ShowArr(arr, kol);
	int method;
	cout << "\n\nКаким методом отсортировать массив? " << endl
		<< "1) Сбалансированное слияние;" << endl
		<< "2) Естественное слияние; " << endl
		<< "3) Многофазное слияние; " <<"\n\n>";
	cin >> method;
	cout << endl;
	vector<int>resultvec;
	switch (method) {
	case 1:
		MergeSort(arr, 0, kol - 1, kol);
		cout << "\n============================= " << endl;
		cout << "\nИзменённый массив массив: ";
		ShowArr(arr, kol);
		break;
	case 2:
		arr = EstesMergeSort(arr, kol, resultvec);
		cout << "\n============================= " << endl;
		cout << "\nИзменённый массив массив: ";
		ShowArr(arr, kol);
		break;
	case 3:
		PolyphaseMergeSort(arr, kol);		
		break;
	}
}
void ShowArr(vector<int>arr, int kol)
{
	for (int i = 0; i < kol; i++) {
		cout << arr[i] << "; ";
	}
	cout << "\n============================= " << endl;
}
void MergeSort(vector<int>& arr, int left, int right, int kol)
{
	if (left < right)
		if (right - left == 1) {
			if (arr[left] > arr[right]) {
				swap(arr[left], arr[right]);
			}
		}
		else {
			MergeSort(arr, left, left + (right - left) / 2, kol);			
			MergeSort(arr, left + (right - left) / 2 + 1, right, kol);			
			Merging(arr, left, right, kol);
		}
}
void Merging(vector<int>& arr, int begin, int end, int kol)
{
	vector<int>tmp(kol);
	int i = begin, mid = begin + (end - begin) / 2, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			tmp[k] = arr[i];
			i++;
		}
		else {
			tmp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		tmp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= end) {
		tmp[k] = arr[j];
		j++;
		k++;
	}
	for (i = 0; i < k; i++) {
		arr[begin + i] = tmp[i];
	}
}
vector<int> EstesMergeSort(vector<int>& arr, int kol, vector<int>& resultvec)
{
	vector<int>tmp, tmp2;
	int ind = 0, count = 0;
	bool flag = true;
	if (kol == 0) {
		return resultvec;
	}
	if (kol == 1) {
		for (int i = 0; i < kol; i++)
			tmp.push_back(arr[i]);
		arr.erase(arr.begin(), arr.begin() + tmp.size());
		kol--;
		for (int i = 0; i < tmp.size(); i++) {
			resultvec.push_back(tmp[i]);
		}
		InsertionSort(resultvec);
		EstesMergeSort(arr, kol, resultvec);
		return resultvec;
	}
	if (kol > 1) {
		for (int i = 0; i < kol - 1 && flag; i++) {
			if (arr[i] <= arr[i + 1]) {
				tmp.push_back(arr[i]);
			}
			else {
				flag = false;
				tmp.push_back(arr[i]);
				ind = i + 1;
			}
			count++;
		}
		flag = true;
		for (int i = ind; i < kol - 1 && flag; i++) {
			if (arr[i] <= arr[i + 1]) {
				tmp2.push_back(arr[i]);
			}
			else {
				flag = false;
				tmp2.push_back(arr[i]);
			}
			count++;
		}
		arr.erase(arr.begin(), arr.begin() + tmp2.size() + tmp.size());
		kol -= count;
		for (int i = 0; i < tmp2.size(); i++) {
			tmp.push_back(tmp2[i]);
		}
		InsertionSort(tmp);
		for (int i = 0; i < tmp.size(); i++) {
			resultvec.push_back(tmp[i]);
		}
		InsertionSort(resultvec);		
		EstesMergeSort(arr, kol, resultvec);
		return resultvec;
	}
}
void PolyphaseMergeSort(vector<int>& arr, int kol)
{
	vector<vector<int>>List;
	bool flag = true;
	int i = 0;
	while (i < arr.size()) {
		vector<int> tmp;
		tmp.push_back(arr[i]);
		i++;
		while (i < arr.size() && arr[i - 1] < arr[i]) {
			tmp.push_back(arr[i]);
			i++;
		}
		List.push_back(tmp);
	}
	vector<vector<int>>F1, F2, F3;
	//числа фибоначи
	int size1, size2;	
	Fib(size1, size2, arr);	
	//инициализация f1, f2
	for (int i = 0; i < size1; i++) {
		F1.push_back(List[i]);
	}
	for (int i = 0; i < List.size() - size1; i++) {
		F2.push_back(List[i + size1]);
	}
	// заполнение пустыми сериями 
	for (int i = List.size(); i < size1 + size2; i++) {
		vector<int> serie;		
		serie.push_back(-999);
		F2.push_back(serie);
	}	
	//вывод на консоль заполненного F1
	cout << "F1 " << endl;	
	PrintSeries(F1);
	//вывод на консоль заполненного F2
	cout << endl << "F2 " << endl;	
	PrintSeries(F2);
	cout << endl;
	//цикл, в котором осуществляется обемен между файлами
	while (!(F1.size() == 0 && F2.size() == 0 || F2.size() == 0 && F3.size() == 0 || F3.size() == 0 && F1.size() == 0)) {
		if ((F1.size() >= F2.size() && F3.size() == 0)) {				
			Transition(F2, F1, F3);
		}
		if ((F2.size() >= F1.size() && F3.size() == 0)) {			
			Transition(F1, F2, F3);
		}
		if ((F3.size() >= F2.size() && F1.size() == 0)) {			
			Transition(F2, F3, F1);
		}
		if ((F2.size() >= F3.size() && F1.size() == 0)) {			
			Transition(F3, F2, F1);
		}
		if ((F1.size() >= F3.size() && F2.size() == 0)) {			
			Transition(F3, F1, F2);
		}
		if ((F3.size() >= F1.size() && F2.size() == 0)) {			
			Transition(F1, F3, F2);
		}
		if (F1.size() != 0) {			
			cout << "\nF1"<< endl;
			PrintSeries(F1);			
		}
		if (F2.size() != 0) {			
			cout << "\nF2"<< endl;
			PrintSeries(F2);
		}
		if (F3.size() != 0) {			
			cout << "\nF3"<< endl;
			PrintSeries(F3);
		}
	}
	cout << "\nИзменённый массив:";
	if (F1.size() != 0) {
		for (int i = 0; i < F1[0].size(); i++) {
			if (F1[0][i] != -999) {
				cout << F1[0][i] << " ";
			}			
		}
	}
	if (F2.size() != 0) {
		for (int i = 0; i < F2[0].size(); i++) {
			if (F2[0][i] != -999)
			cout << F2[0][i] << " ";
		}
	}
	if (F3.size() != 0) {
		for (int i = 0; i < F3[0].size(); i++) {
			if (F3[0][i] != -999)
			cout << F3[0][i] << " ";
		}
	}
	cout << endl;
}
void Fib(int& size1, int& size2, vector<int>& arr)
{
	size1 = 0;
	size2 = 1;
	while (size1 + size2 < arr.size()) {
		int tmp = size2;
		size2 = size2 + size1;
		size1 = tmp;
	}
}
void PrintSeries(vector<vector<int>> series)
{
	cout << series.size() << " - ";
	for (int i = 0; i < series.size(); i++) {
		cout << "(";
		for (int j = 0; j < series[i].size(); j++) {
			cout << series[i][j] << " ";
		}
		cout << ")";
	}
	cout << endl;
}
void InsertionSort(vector<int>&newSerie)
{
	for (int i = 0; i < newSerie.size(); i++) {
		for (int j = i; j > 0 && newSerie[j - 1] > newSerie[j]; j--) {
			swap(newSerie[j - 1], newSerie[j]);
		}
	}
}
void Transition(vector<vector<int>>&min, vector<vector<int>>&max, vector<vector<int>>&nullel)
{
	for (int i = 0; i < min.size(); i++) {
		vector<int> serie1 = max[i], serie2 = min[i];
		vector<int> newSerie = serie1;
		for (int j = 0; j < serie2.size(); j++) {
			newSerie.push_back(serie2[j]);
		}
		InsertionSort(newSerie);
		nullel.push_back(newSerie);
	}	
	max.erase(max.begin(), max.begin() + min.size());
	min.clear();
}