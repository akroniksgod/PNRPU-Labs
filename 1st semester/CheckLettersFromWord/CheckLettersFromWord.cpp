#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char letter;
	cout << "Введите букву: ";
	cin >> letter;
	switch (letter)
	{
	case 'и':
		cout << "Буква и есть в слове\n";
		break;
	case 'н':
		cout << "Буква н есть в слове\n";
		break;
	case 'ф':
		cout << "Буква ф есть в слове\n";
		break;
	case 'о':
		cout << "Буква о есть в слове\n";
		break;
	case 'р':
		cout << "Буква р есть в слове\n";
		break;
	case 'м':
		cout << "Буква м есть в слове\n";
		break;
	case 'а':
		cout << "Буква а есть в слове\n";
		break;
	case 'т':
		cout << "Буква т есть в слове\n";
		break;
	case 'к':
		cout << "Буква к есть в слове\n";
		break;
	default:
		cout << "Буквы " << letter << " нет в слове\n";
		break;
	}
}