#include "Vector.h"
#include "error.h"
Vector::Vector()
{
	size = 0;
	beg = 0;
}
Vector::Vector(int s)
{
	if (s > MAX_SIZE) throw error("Был введён размер, больший максимального (20)!\n");
	if (s < 0) throw error("Был введён отрицательный размер!\n");
	if (s == 0) throw error("Размер не должен быть равным нулю!\n");
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++) {
		beg[i] = rand() % 100;
	}
}
Vector::Vector(const Vector& vec)
{
	size = vec.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) {
		beg[i] = vec.beg[i];
	}
}
Vector::~Vector()
{
	if (beg != NULL)
		delete[] beg;
}
int Vector::operator[](int index)
{
	if (index > MAX_SIZE)
		throw error("Был введён индекс, больший максимального (20)!\n");
	if (index >= size)
		throw error("Был введён индекс, больший размера вектора!\n");
	if (index < 0)
		throw error("Был введён отрицательный индекс!\n");
	return beg[index];
}
int Vector::operator()()
{
	return size;
}
Vector Vector::operator--()
{
	if (size == 0)
		throw error("Ошибка! Вектор не может иметь отрицательный размер\n");
	if (size == 1) {
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = beg[i];
	}
	size--;
	delete[] beg;
	beg = temp;
	temp = NULL;
	return *this;
}
Vector Vector::operator--(int)
{
	if (size == 0)
		throw error("Ошибка! Вектор не может иметь отрицательный размер\n");
	if (size == 1) {
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = beg[i + 1];
	}
	size--;
	delete[] beg;
	beg = temp;
	temp = NULL;
	return *this;
}
void Vector::get_Vector()
{
	for (int i = 0; i < size; i++) {
		cout << beg[i] << "; ";
	}
	cout << endl;
}
const Vector& Vector::operator=(const Vector& vec)
{
	if (this == &vec) return *this;
	if (beg != 0) delete[] beg;
	size = vec.size;
	beg = new int[size];
	for (int i = 0; i << size; i++) {
		beg[i] = vec.beg[i];
	}
	return *this;
}
