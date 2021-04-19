#include "Print.h"
Print::Print()
{
	author = "";
	name = "";
}
Print::~Print()
{
}
void Print::Show()
{
	cout << "Название печатного издания: " << name << endl
		<< "Автор: " << author << "\n\n";
}
void Print::Input()
{
	cout << "Введите название печатного издания: ";
	getline(cin, name);
	cout << "Введите автора: ";
	getline(cin, author);
	cout << endl;
}
Print::Print(string Name, string Author)
{
	name = Name;
	author = Author;
}
Print::Print(const Print& other)
{
	author = other.author;
	name = other.name;
}
string Print::Get_name()
{
	return name;
}
string Print::Get_author()
{
	return author;
}
void Print::Set_name(string newName)
{
	name = newName;
}
void Print::Set_author(string newAuthor)
{
	author = newAuthor;
}
Print& Print::operator=(const Print& other)
{
	if (&other == this)
		return *this;
	name = other.name;
	author = other.author;
	return *this;
}
void Print::HandleEvent(TEvent& event)
{
	if (event.what == evMessage) {
		switch (event.command) {
		case cmGet: { cout << "Наменование: " << Get_name() << endl;  }break;
		}
	}
}