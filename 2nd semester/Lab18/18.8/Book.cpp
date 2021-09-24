#include "Book.h"
namespace foo
{
	int SafeInput(bool strict)
	{
		int result;
		while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ���������� �����!" << endl;
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
	cout << "������� �������� ������������: ";
	getline(cin, office);
	cout << "������� ���������� �������: ";
	pages = foo::SafeInput(true);
	cout << "������� �������� ��������� �������: ";
	getline(cin, name);
}
void Book::Show()
{
	cout << "�������� ������������: " << office
		<< endl << "���������� �������: " << pages << endl << endl;
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