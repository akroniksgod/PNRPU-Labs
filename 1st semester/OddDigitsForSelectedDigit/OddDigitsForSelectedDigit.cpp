#include <iostream>

int main()
{
	setlocale(LC_ALL, "Ru");
	int c;
	std::cout << "Введите цифру: ";
	std::cin >> c;
	switch (c)
	{
	case 0:
	case 1:
		std::cout << 1 << " ";
	case 2:
	case 3:
		std::cout << 3 << " ";
	case 4:
	case 5:
		std::cout << 5 << " ";
	case 6:
	case 7:
		std::cout << 7 << " ";
	case 8:
	case 9:
		std::cout << 9 << " ";
		break;
	default:
		std::cout << "Введена не цифра\n";
		break;
	}
}