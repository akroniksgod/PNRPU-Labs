#include<iostream>
#include<iterator>
#include<list>
using namespace std;
list<int>List;
list<int>::iterator iter;
void make(int n) {
	int tmp;
	for (int i = 1; i <= n; i++) {
		cout << "Введите " << i << " элемент: ";
		cin >> tmp;
		List.push_back(tmp);
	}
}
void Deletion(int n) {	
	iter = List.begin();
	iter++;
	iter = List.erase(iter);
	iter=List.end();
	n--;
}
int main()
{		
	setlocale(LC_ALL, "ru");
	int size = 0;
	while (size < 1) {
		cout << "Введите размер списка: ";
		cin >> size;
	}
	make(size);
	cout << "Ваш список: " << endl;
	copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	if (size > 1) {
		cout << "\nУдаление первого элемента с чётным полем..." << endl;
		Deletion(size);
		copy(List.begin(), List.end(), ostream_iterator<int>(cout, " "));
	}
}