#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;
struct CarOwner
{
public:
	string name, nam, num;
	int tel, passp;
	void Input()
	{
		cout << "Введите Фамилию: ";
		cin >> name;
		while (cin.get() != '\n'); //исправление ошибки с консолью		
		cout << "Имя и отчество ";
		getline(cin, nam);
		cout << "\nВведите номер автомобиля: ";
		getline(cin, num);
		cout << "Введите номер телефона: ";
		cin >> tel;
		cout << "Введите номер техпаспорта: ";
		cin >> passp;
		cout << endl;
	}
	void Output()
	{
		cout << "\nФамилия: " << name
			<< "\n Имя, отчество " << nam
			<< "\nНомер автомобиля: " << num
			<< "\nТелефон: " << tel
			<< "\nТехпаспорт: " << passp << endl;
	}
};
void InputList(int kol, CarOwner* owner);
CarOwner InputNew(CarOwner* arr);
int Deletion(int kol, CarOwner* owner, string nomer);
void Printing(int kol, CarOwner* owner);
int Addition(int kol, CarOwner* owner, string imya, CarOwner* arr);
int main()
{
	setlocale(LC_ALL, "Ru");
	system("chcp 1251>nul");
	int kol = -1;
	while (kol < 1 || kol>6)
	{
		cout << "Количество человек от 1 до 5:  ";
		cin >> kol;
	}
	cout << endl;
	CarOwner* owner = new CarOwner[kol];
	CarOwner arr[2];
	InputList(kol, owner);
	cout << "Введите номер элемента, который необходимо удалить: " << endl;
	string nomer, imya;
	while (cin.get() != '\n');
	getline(cin, nomer);
	kol = Deletion(kol, owner, nomer);
	cout << "------------------------------------";
	Printing(kol, owner);
	cout << "------------------------------------";
	cout << "\nПеред кем добавить 2 элемента? (введите фамилию): ";
	getline(cin, imya);
	kol = Addition(kol, owner, imya, arr);
	cout << "------------------------------------";
	delete[] owner;
	return 0;
}
void InputList(int kol, CarOwner* owner)
{
	for (int i = 0; i < kol; i++)
	{
		owner[i].Input();
	}
}
int Deletion(int kol, CarOwner* owner, string nomer)
{
	int i = 0, tmp;
	bool flag = false;
	while ((!flag) && (i <= kol))
	{
		if (nomer == owner[i].num)
		{
			flag = true;
			for (int j = i; (j < kol - 1); j++)
			{
				owner[j] = owner[j + 1];
			}
			kol--;
		}
		i++;
	}
	if (flag == false)
		cout << "Такой номера не нашлось!" << endl;
	return kol;
}
void Printing(int kol, CarOwner* owner)
{
	for (int i = 0; i < kol; i++)
	{
		owner[i].Output();
	}
}
int Addition(int kol, CarOwner* owner, string imya, CarOwner* arr)
{
	bool flag = false;
	int tmp = 0, position, count = 0;
	while ((!flag) && (tmp <= kol))
	{
		if (imya == owner[tmp].name)
		{
			flag = true;
			position = tmp;
		}
		tmp++;
	}
	if (flag)
	{
		vector<CarOwner>massiv(owner, owner + kol);
		massiv.reserve(kol + 2);
		kol += 2;
		for (int i = 0; i < 2; i++)
		{
			massiv.insert(massiv.begin() + position, 1, InputNew(arr));
		}
		cout << "------------------------------------";
		for (int i = 0; i < kol; i++)
		{
			massiv[i].Output();
		}
	}
	else
		cout << "Такой фамилии нет! " << endl;
	return kol;
}
CarOwner InputNew(CarOwner* arr)
{
	for (int i = 0; i < 1; i++)
	{
		arr[i].Input();
	}
	return *arr;
}