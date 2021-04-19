#pragma once
#include<iostream>
using namespace std;
template<class Type>
class Vector
{
protected:
	Type *arr;
	int size;
public:
	Vector(int length, Type ptr); //конструктор с параметрами	
	Vector(const Vector& object); //конструктор копирования	
	~Vector();	//очистка памяти
	Vector& operator=(const Vector<Type>& other); 	
	Type& operator[] (int index); //получение значения по индексу	
	Vector operator+(const Type k); //сложение элемента массива с константой	
	int operator()(); //получение размера	
	friend ostream& operator<< (ostream& out, const Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			out << p.arr[i] << " ";
		}
		return out;
	}
	friend istream& operator>> (istream& in, Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			in >> p.arr[i];
		}
		return in;
	}
};
#include "Vector.cpp"