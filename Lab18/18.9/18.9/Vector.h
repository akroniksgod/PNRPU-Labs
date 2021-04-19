#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class Vector
{
	int size; //текущий размер
	int* beg;//указатель на начало вектора
public:
	Vector();
	Vector(int s);
	Vector(const Vector& vec);
	~Vector();
	const Vector& operator=(const Vector& vec);
	int operator[](int index);
	int operator()();
	Vector operator--(int); //удаление первого элемента
	Vector operator--(); //удаление последнего элемента
	void get_Vector();
};