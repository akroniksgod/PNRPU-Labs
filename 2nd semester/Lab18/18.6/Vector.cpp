#include "Vector.h"
Vector::Vector()
{
	size = 0;
	head = 0;
}
Vector::Vector(int s)
{
	size = s;
	head = new int[size];
	for (int i = 0; i < size; i++) {
		head[i] = rand() % 100;
	}
	beg.element = &head[0];
	end.element = &head[size - 1];
}
Vector::Vector(const Vector& vec)
{
	size = vec.size;
	head = new int[size];
	for (int i = 0; i < size; i++) {
		head[i] = vec.head[i];
	}
	beg = vec.beg;
	end = vec.end;
}
Vector::~Vector()
{
	if (head != NULL)
		delete[] head;
}
int Vector::operator[](int index)
{
	if (index < size)
		return head[index];
	else
		throw 1;
}
int Vector::operator()()
{
	return size;
}
Vector Vector::operator--()
{
	if (size > 0) {
		if (size == 1) {
			size = 0;
			delete[] head;
			head = 0;
			return *this;
		}
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++) {
			temp[i] = head[i];
		}
		size--;
		delete[] head;
		head = temp;
		temp = NULL;
		return *this;
	}
	else
		cout << "Error!";
}
void Vector::get_Vector()
{
	for (int i = 0; i < size; i++) {
		cout << head[i] << "; ";
	}
	cout << endl;
}
const Vector& Vector::operator=(const Vector& vec)
{
	if (this == &vec) return *this;
	if (head != 0) delete[] head;
	size = vec.size;
	head = new int[size];
	for (int i = 0; i << size; i++) {
		head[i] = vec.head[i];
	}
	beg = vec.beg;
	end = vec.end;
	return *this;
}
void Vector::operator*(const int num)
{
	for (int i = 0; i < size; i++) {
		head[i] *= num;
	}
}
ostream& operator <<(ostream& out, const Vector& a)
{
	for (int i = 0; i < a.size; i++) {
		out << a.head[i] << "; ";
	}
	cout << endl;
	return out;
}
Iterator Vector::first()
{
	return beg;
}
Iterator Vector::last()
{
	return end;
}
void Vector::operator-=(const int n)
{
	if (n < size) {
		Iterator it = last();
		for (int i = 0; i < n; i++) {
			--it;
		}
		cout << "Iterator->" << *it << endl;
	}
	else
		cout << "Error!";
}