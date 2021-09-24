#pragma once
#include <iostream>
#include <ctime>
#include "Iterator.h"
using namespace std;
class Vector {
protected:
	int size; //текущий размер
	int* head;//указатель на начало вектора
	Iterator beg;
	Iterator end;
public:
	Vector();
	Vector(int s);
	Vector(const Vector& vec);
	~Vector();
	const Vector& operator=(const Vector& vec);
	int operator[](int index);
	int operator()();
	void operator*(const int num);
	Vector operator--(); //удаление последнего элемента
	void get_Vector();
	friend ostream& operator <<(ostream& out, const Vector& a);
	Iterator first();
	Iterator last();
	void operator -=(const int n);	
};