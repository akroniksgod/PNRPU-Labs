#include "Vector.h"
#include "Abstract.h"
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
	beg = new Abstract * [n];
	current = 0;
	size = n;
}
void Vector::push(Abstract* pointer)
{
	if (current < size) {
		beg[current] = pointer;
		current++;
	}
	else
		cout << "Ошибка добавления" << endl;
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0)
		out << "Вектор пуст!" << endl;
	Abstract** p = v.beg;//указатель на указатель типа Abstract
	for (int i = 0; i < v.current; i++) {
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//сдвиг указателя на сдед. элемент
	}
	return out;
}