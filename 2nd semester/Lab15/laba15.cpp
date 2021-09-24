#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;
struct Spisok
{
	string lang, fam;
};
void shellsort(vector<Spisok>& items, int size)
{
	int j;
	string tmpfam, tmplang;
	for (int step = size / 2; step > 0; step /= 2) {
		for (int i = step; i < size; i++) {
			tmpfam = items[i].fam;
			tmplang = items[i].lang;
			for (j = i; j >= step; j -= step) {
				if (tmpfam < items[j - step].fam) {
					items[j].fam = items[j - step].fam;
					items[j].lang = items[j - step].lang;
				}
				else
					break;
			}
			items[j].fam = tmpfam;
			items[j].lang = tmplang;
		}
	}
}
void quicksort(vector <Spisok>& items, int left, int right)
{
	int i, j, pivot;
	string tmpfam, tmplang;
	stack<int>stk;
	stk.push(left); //хранение левой границы в стеке
	stk.push(right); //хранение правой границы в стеке
	do {
		right = stk.top(); //достаём правую границу массива перед левой по принципу работы стека
		stk.pop(); //очистка стека от right
		left = stk.top(); //достаём левую границу массива
		stk.pop(); //очистка стека от left
		i = left;
		j = right;
		pivot = items[(right + left) / 2].fam[0]; //инициализация опорного элемента
		do {
			while (items[i].fam[0] < pivot) i++;//сдвигаем левый указатель вправо
			while (pivot < items[j].fam[0]) j--;//свдигаем правый указатель влево
			if (i <= j) {
				tmpfam = items[i].fam; //обмен фамилиями
				items[i].fam = items[j].fam; //обмен фамилиями
				items[j].fam = tmpfam;//обмен фамилиями
				tmplang = items[i].lang;//обмен яз прог 
				items[i].lang = items[j].lang;//обмен яз прог
				items[j].lang = tmplang;//обмен яз прог				
				i++;
				j--;
			}
		} while (i <= j);
		if (left < j) {
			stk.push(left);
			stk.push(j);
		}
		if (i < right) {
			stk.push(i);
			stk.push(right);
		}
	} while (!stk.empty()); //завершение цикла после очистки стека
}
int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251>nul");
	int n = -1;
	while (n < 1) {
		cout << "Сколько элементов в списке?  ";
		cin >> n; // сколько элементов будет
	}
	vector <Spisok> array(n);
	for (int i = 0; i < n; i++) {
		cout << "Язык программирования - ";
		cin >> array[i].lang;
		cout << "Фамилия - ";
		cin >> array[i].fam;
	}
	cout << "\nКаким методом отсортировать: " << endl
		<< "1) Метод Хоара;" << endl
		<< "2) Сортировка Шелла;" << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		quicksort(array, 0, n - 1);
		cout << "\n\n" << "Результат" << endl;
		for (int i = 0; i < n; i++) {//вывод отсортированного массива
			cout << array[i].lang << " : " << array[i].fam << endl;
		}//вывод отсортированного массива
		break;
	case 2:
		shellsort(array, n);
		for (int i = 0; i < n; i++) {//вывод отсортированного массива
			cout << array[i].lang << " : " << array[i].fam << endl;
		}//вывод отсортированного массива
		break;
	}
}