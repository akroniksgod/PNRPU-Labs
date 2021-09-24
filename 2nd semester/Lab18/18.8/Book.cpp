#include "Book.h"
namespace foo
{
	int SafeInput(bool strict)
	{
		int result;
		while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Введите корректное число!" << endl;
		}
		cin.get();
		return result;
	}
}
Book::Book()
{
	pages = 0;
	office = "";
}
Book::Book(int Pages, string Office)
{
	pages = Pages;
	office = Office;
}
Book::Book(const Book& other)
{
	pages = other.pages;
	office = other.office;
}
Book::~Book()
{
}
void Book::Input()
{
	cout << "Введите название издательства: ";
	getline(cin, office);
	cout << "Введите количество страниц: ";
	pages = foo::SafeInput(true);
	cout << "Введите название печатного издания: ";
	getline(cin, name);
}
void Book::Show()
{
	cout << "Название издательства: " << office
		<< endl << "Количество страниц: " << pages << endl << endl;
}
int Book::Get_pages()
{
	return pages;
}
string Book::Get_office()
{
	return office;
}
Book& Book::operator=(const Book& other)
{
	if (&other == this)
		return *this;
	pages = other.pages;
	office = other.office;
	return *this;
}