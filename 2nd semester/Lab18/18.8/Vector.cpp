#include "Vector.h"
#include "Object.h"
#include "Print.h"
#include "Book.h"
namespace foo2
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
Vector::Vector()
{
	beg = 0;
	size = 0;
	current = 0;
}
Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	current = 0;
	size = n;
}
void Vector::push()
{
	Object* pointer;
	cout << "1.Print " << endl
		<< "2. Book " << endl << ">";
	int vvod = foo2::SafeInput(true);
	if (vvod == 1) {
		Print* a = new Print;
		a->Input();
		pointer = a;
		if (current < size) {
			beg[current] = pointer;
			current++;
		}
		else
			cout << "Ошибка добавления" << endl;
	}
	else if (vvod == 2) {
		Book* b = new Book;
		b->Input();
		pointer = b;
		if (current < size) {
			beg[current] = pointer;
			current++;
		}
		else
			cout << "Ошибка добавления" << endl;
	}
	else
		return;
}
void Vector::pop()
{
	if (current == 0)
		return;//пустой
	if (current > 0)
		current--;

}
void Vector::Show()
{
	if (current == 0)
		cout << "Вектор пуст!" << endl;
	else {
		Object** p = beg;
		for (int i = 0; i < current; i++) {
			(*p)->Show();
			p++;
		}
		cout << endl;
	}
}
void Vector::HandleEvent(TEvent& event)
{
	if (event.what == evMessage) {
		Object** p = beg;
		for (int i = 0; i < current; i++) {
			(*p)->HandleEvent(event);
			p++;
		}
	}
}
int Vector::operator ()()
{
	return current;
}
//ostream& operator<<(ostream& out, const Vector& v)
//{
//	if (v.size == 0)
//		out << "Вектор пуст!" << endl;
//	Object** p = v.beg;//указатель на указатель типа Abstract
//	for (int i = 0; i < v.current; i++) {
//		(*p)->Show();//вызов метода Show() (позднее связывание)
//		p++;//сдвиг указателя на сдед. элемент
//	}
//	return out;
//}