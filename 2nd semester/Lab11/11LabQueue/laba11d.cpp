#include<iostream>
using namespace std;
struct Queue{
	int data;
	Queue* next;
};
Queue* Make(int size, Queue*& first, Queue*& last);
void GetLine(Queue* last);
void Deletion(Queue*& first, Queue*& last);
int main()
{
	setlocale(LC_ALL, "Ru");
	int size=-1;
	while (size<0) {
		cout << "Ввести количество элементов в очереди: ";
		cin >> size;
	}
	Queue* first, * last;
	Make(size, first, last);
	cout << "Очередь: ";
	GetLine(last);
	Deletion(first, last);
	GetLine(last);
}
Queue* Make(int size, Queue*& first, Queue*& last)
{
	if (size == 0) return NULL;
	Queue* p = new Queue;
	int x;
	cout << "Введите первый элемент очереди: ";
	cin >> x;
	p->data = x;
	p->next = NULL;
	first = p;
	last = p;
	for (int i = 2; i <= size; i++) {
		Queue* nex = new Queue;
		cout << "Введите " << i << " элемент: ";
		cin >> x;
		nex->data = x;
		nex->next = p;
		last = nex;
		p = last;
	}
	return first;
}
void Deletion(Queue*& first, Queue*& last)
{
	bool flag = true;	
	Queue* p = last;
	Queue* prev = NULL;
	while (p!= NULL) {
		if (p->data % 2 == 0 && flag) {			
			Queue* temp = p;
			if (prev != NULL) {
				prev->next = p->next;
			}
			else {				
				last= p->next;
			}
			
			p = p->next;
			delete temp;			
			flag = false;
		}
		else {
			prev = p;
			p = p->next;
		}
		
	}	
}
void GetLine(Queue* last)
{
	Queue* p = last;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}