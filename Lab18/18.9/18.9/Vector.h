#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class Vector
{
	int size; //������� ������
	int* beg;//��������� �� ������ �������
public:
	Vector();
	Vector(int s);
	Vector(const Vector& vec);
	~Vector();
	const Vector& operator=(const Vector& vec);
	int operator[](int index);
	int operator()();
	Vector operator--(int); //�������� ������� ��������
	Vector operator--(); //�������� ���������� ��������
	void get_Vector();
};