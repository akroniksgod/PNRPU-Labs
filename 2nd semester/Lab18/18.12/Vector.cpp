#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_
#include "Vector.h"
#include <assert.h>
using namespace std;
template<class Type>
Vector<Type>::Vector()
{
	size = 0;
}
template<class Type>
Vector<Type>::Vector(int length)
{
	size = length;	
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
	//delete[] arr;
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
void Vector<Type>:: operator+(const Type k)
{	
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = arr[i] + k;
	}	
}
template<class Type>
int Vector<Type>::operator()()
{
	return size;
}
template<class Type>
void Vector<Type>::PrintMap()
{
	for (int i = 0; i < arr.size(); i++) {
		cout << i << ": " << arr[i] << endl;
	}
	cout << endl;
}
template<class Type>
int Vector<Type>::FindAverageValue()
{
	int result = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		result += arr[i];
	}
	return (result / arr.size());
}
template<class Type>
void Vector<Type>::insert(int pos, Type element)
{
	arr.insert(make_pair(pos, element));
}
#endif