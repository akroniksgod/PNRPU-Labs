#pragma once
#include <iostream>
using namespace std;
class Pair {
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
class Complex: public Pair {
	int real, imaginary;
public:
	Complex();	
	Complex(Pair fir, Pair sec);
	~Complex();
	int getReal();
	int getImag();
	void SetReal(Pair a, Pair b);
	void SetImag(Pair a, Pair b);
	Complex operator*(const Complex& t);	
	void ShowComplex();
};