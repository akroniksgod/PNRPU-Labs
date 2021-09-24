#pragma once
#include "Pair.h"
class Complex : public Pair {
protected:
	int real, imaginary;
public:
	Complex();
	Complex(Pair fir, Pair sec);
	~Complex();
	int getReal();
	int getImag();
	void SetReal(Pair a, Pair b);
	void SetImag(Pair a, Pair b);	
	void Show();
};