#include<iostream>
using namespace std;
struct Stack {
	char data;
	Stack* prev;
};
Stack* MakeStack(int size);
void GetStack(Stack* top);
Stack* Addition(Stack*& top);
void GetStack2(Stack* top,int size);
int main()
{
	setlocale(LC_ALL, "ru");
	int size = -1;
	while (size < 0) {
		cout << "Ввести количество элементов в стеке: ";
		cin >> size;
	}
	Stack* stk=MakeStack(size);
	GetStack(stk);
	Addition(stk);
	cout << "Результат: ";
	//GetStack(stk);
	GetStack2(stk, size*2);
}
Stack* MakeStack(int size)
{
	char x;
	if (size == 0) return NULL;
	Stack* top, * p;
	top = NULL;
	p = new Stack;
	cout << "Введите 1 элемент: ";
	cin >> x;
	p->data = x;
	p->prev = NULL;
	top = p;
	for (int i = 2; i <= size; i++) {
		Stack* nex = new Stack;
		cout << "Введите " << i << " элемент: ";
		cin >> x;
		nex->data = x;
		nex->prev = top;
		top = nex;
	}
	return top;
}
void GetStack(Stack* top)
{
	if (top == 0) cout << "Стек пуст! ";
	else {
		Stack* p = top;
		while (p != NULL) {
			cout << p->data << " ";
			p=p->prev;
		}
		cout << endl;
	}
}
Stack* Addition(Stack*& top)
{
	char x;	
	int i=0;
	cout << "Введите элемент для вставки: ";
	cin >> x;
	Stack* p = top;
	Stack * tmp = NULL;
	while (p != NULL) {
		Stack* newE = new Stack;
		newE->data = x;
		newE->prev = p;
		if (tmp != NULL)
			tmp->prev = newE;
		else
			top = newE;
		tmp = p;
		p = p->prev;
	}
	return top;
}
void GetStack2(Stack* top,int size)
{
	Stack* p = top;
	char* arr = new char[size];
	for (int i = 0; i < size && p!=NULL ; i++) {
		arr[i] = p->data;
		p = p->prev;
	}
	for (int i = size-1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
	delete[] arr;
}