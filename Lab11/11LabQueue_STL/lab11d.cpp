#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void GetLine(queue<int>line);
void Deletion(queue<int>&line);
int main()
{
	setlocale(LC_ALL, "ru");
	int size = 0;
	while (size < 1) {
		cout << "Введите размерность очереди: ";
		cin >> size;
	}
	vector<int> arr(size);
	queue<int> line;
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i << " элемент: ";
		cin >> arr[i];
		line.push(arr[i]);
	}
	cout << "Введённая очередь - ";
	GetLine(line);
	Deletion(line);
	cout << "Изменённая очередь - ";
	GetLine(line);
}
void GetLine(queue<int>line)
{
	int size = line.size();	
	for (int i = 1; i <= size; i++) {
		cout << line.front() << " ";
		line.pop();
	}
	cout << endl;
}
void Deletion(queue<int>&line)
{	
	bool flag = true;
	int j = 0;
	int size = line.size();
	vector<int> tmp(size);
	while (j < size) {
		if (line.front() % 2 == 0&&flag) {
			line.pop();
			size--;
			flag = false;
		}
		else {
			tmp[j] = line.front();
			line.pop();
			j++;
		}
	}
	for (int i= 0; i < size; i++) {
		line.push(tmp[i]);		
	}	
}