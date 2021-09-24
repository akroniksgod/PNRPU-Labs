#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void GetStack(stack<char>stk);
void Addition(stack<char>&stk, int size);
int main()
{
	setlocale(LC_ALL, "ru");
	stack<char>stk;
	char x;
	int size=-1;
	while (size < 0) {
		cout << "Ввести количество элементов в стеке: ";
		cin >> size;
	}	
	for (int i = 1; i <= size; i++) {
		cout << "Введите " << i << " элемент: ";
		cin >> x;
		stk.push(x);
	}
	cout << "Стек: ";
	GetStack(stk);
	Addition(stk,size);
	GetStack(stk);
}
void GetStack(stack<char>stk)
{
	int size = stk.size();
	if (size == 0) {
		cout << "Стек пуст!" << endl;
	}
	else {
		for (int i = 1; i <= size; i++) {
			cout << stk.top() << " ";
			stk.pop();
		}		
	}
	cout << endl;
}
void Addition(stack<char>& stk, int size)
{
	vector<char>tmp(size);		
	char x;
	cout << "Введите элемент для вставки: ";
	cin >> x;
	for (int i = 0; i < size; i++) {
		tmp[i] = stk.top();
		stk.pop();
	}	
	for (int i = 0; i < size; i++) {
		stk.push(x);
		stk.push(tmp[i]);
	}
}