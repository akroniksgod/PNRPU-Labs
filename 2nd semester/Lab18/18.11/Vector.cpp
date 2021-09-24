#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_
#include "Vector.h"
#include <assert.h>
using namespace std;
template<class Type>
Vector<Type>::Vector(int length, Type ptr)
{
	size = length;
	arr = new Type[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
}
template<class Type>
Vector<Type>::Vector(const Vector& object)
{
	size = object.size;
	arr = new Type[size];
	for (int i = 0; i < size; i++) {
		arr[i] = object.arr[i];
	}
}
template<class Type>
Vector<Type>::~Vector()
{
	delete[] arr;
}
template<class Type>
Vector<Type>& Vector<Type>:: operator=(const Vector<Type>& other)
{
	if (this == &other)
		return *this;
	if (arr != 0)
		delete[] arr;
	size = other.size;
	arr = new Type[size];
	for (int i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}
template<class Type>
Type& Vector<Type>:: operator[] (int index)
{
	if (index < size)
		return arr[index];
	else
		cout << "Error" << endl;
}
template<class Type>
Vector<Type> Vector<Type>:: operator+(const Type k)
{
	Vector<Type> temp(size, k);
	for (int i = 0; i < size; i++) {
		temp.arr[i] = arr[i] + k;
	}
	return temp;
}
template<class Type>
int Vector<Type>::operator()()
{
	return size;
}
template<class Type>
void Vector<Type>::push_back(const Type newElement)
{
	Type* temp = new Type[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	temp[size++] = newElement;
	delete[] arr;
	arr = temp;
	temp = NULL;
}
template<class Type>
int Vector<Type>::get_size()
{
	return size;
}
#endif