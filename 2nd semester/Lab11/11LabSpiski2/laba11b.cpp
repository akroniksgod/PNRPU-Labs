#include<iostream>
using namespace std;
struct List {
	int data;	
	List* next=NULL;
	List* prev=NULL;
};
List* make(int size);
void GetList(List* first);
void Deletion(List* &first);
int main()
{
	setlocale(LC_ALL, "Ru");
	int size = 0;
	while (size <1) {
		cout << "Введите размер списка: ";
		cin >> size;
	}
	List* list = make(size);
	cout << "Ваш список: " << " ";	
	GetList(list);
	if (size > 1) {
		cout << "Удаление первого элемента с чётным полем..." << endl;
		Deletion(list);
		GetList(list);
	}
}
List* make(int size)
{
	if (size == 0) {
		cout << "Список пуст!" << endl;
		return 0;
	}	
	List* head = new List;
	cout << "Введите 1 элемент: ";
	List* p = head;
	cin >> head->data;
	for (int i = 2; i <= size; i++) {
		List* body = new List;
		p->next = body;
		cout << "Введите " << i << " элемент: ";
		cin >> body->data;
		body->prev = p;
		p = body;
	}
	return head;	
}
void GetList(List* first)
{
	if (first == NULL)
		cout << "Список пуст!" << endl;
	else {
		List* p = first;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
			}
		cout << endl;
	}
}
void Deletion(List*& first)
{	
	if (first == NULL)
		cout << "Список пуст!" << endl;
	else {
		List* p = first;
		int i = 1;
		bool flag = true;
		while (p != NULL && flag) {
			if (i == 2) {
				List* thiz = p;
				if (p->prev) {
					p->prev->next = thiz->next;
					p->next->prev = p->prev;
				}
				else {
					first = p->next;
				}
				delete thiz;
				flag = false;				
			}
			p = p->next;			
			i++;
		}		
	}	
}