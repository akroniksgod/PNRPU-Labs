#pragma once
#include<iostream>
#include <string>
using namespace std;
class Number {
	float mant; // мантисса
	int poryadok; 
	string stroka;
public:
	Number();
	Number(float value, int poryad, float mantissa);
	Number(const Number& other);
	~Number();
	float GetStroka();
	void SetStroka(float key);
	int GetPoryadok(float key);
	void SetPoryadok(int value);
	float GetMant(float key);
	void SetMant(const float value);
	void Show();
};