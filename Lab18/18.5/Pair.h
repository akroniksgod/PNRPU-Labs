#pragma once
#include <iostream>
#include "Abstract.h"
using namespace std;
class Pair : public Abstract {
protected:
	int first, second;
public:
	Pair();
	Pair(int first, int second);
	Pair(const Pair& other);
	~Pair();	
	int GetFirst();
	int GetSecond();
	int GetF();
	int GetS();
	void SetFirst(int value);
	void SetSecond(int value);
	void Show();
	Pair operator+(const Pair& t);
	Pair operator-(const Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
	friend istream& operator>>(istream& in, Pair& t);
};
