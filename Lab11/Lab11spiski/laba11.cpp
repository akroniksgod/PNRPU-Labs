#include<iostream>
using namespace std;
struct List {
	char data;
	List* next;	
};
void GetList(List* first);
List* make(int size);
List* make2(List* first);
int main()
{
	setlocale(LC_ALL, "Ru");
	int size = 0;
	while (size < 1) {
		cout << "Введите размер списка: ";
		cin >> size;
	}
	List* list = make(size);
	cout << "Ваш список: " << endl;
	GetList(list);
	make2(list);
	GetList(list);
}
List* make(int size)
{
	if (size == 0) {
		cout << "Список пуст!" << endl;
		return 0;
	}
	List* first, * p;
	first = NULL;
	cout << "Введите 1 элемент: ";
	p = new List;
	cin >> p->data;
	first = p;
	for (int i = 2; i <= size; i++) {
		List* nex = new List;
		p->next = nex;
		p = p->next;
		cout << "Введите " << i << " элемент: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}
void GetList(List* first)
{
	if (first == NULL)
		cout << "Список пуст!" << endl;
	else {
		List* p = first;
		while (p!=NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}
List* make2(List* first)
{
	char x;
	cout << "Введите элемент для вставки: ";
	cin >> x;
	int i = 1;
	List* p = first;
	while (p!=NULL) {
		if (i % 2 != 0) {
			List* old = p->next;
			List* newElement = new List;			
			newElement->data=x;
			newElement->next = old;
			p->next = newElement;			
		}
		i++;
		p = p->next;
	}
	return first;
}