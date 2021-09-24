#pragma once
#include<iostream>
#include<map>
using namespace std;
template<class Type>
class Vector
{
protected:
	map<int, Type> arr;//Type* arr;
	int size;
public:
	Vector();
	Vector(int length); //конструктор с параметрами	
	Vector(const Vector& object); //конструктор копирования	
	~Vector();	//очистка памяти
	Vector& operator=(const Vector<Type>& other);
	Type& operator[] (int index); //получение значения по индексу	
	void operator+(const Type k); //сложение элемента массива с константой	
	int operator()(); //получение размера	
	void PrintMap();
	int FindAverageValue();
	void insert(int pos, Type element);
	friend ostream& operator<< (ostream& out, const Vector<Type>& p)
	{
		for (int i = 0; i < p.size; i++) {
			out << p.arr[i] << " ";
		}
		cout << endl;
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