#include "Number.h"
using namespace std;
Number::Number()
{
}
Number::~Number()
{
}
float Number::GetStroka()
{
	float str;
	cout << "Введите число (если дробное, то через точку) >";
	cin >> str;
	return str;
}
void Number::SetStroka(float key)
{
	stroka = to_string(key);
}
int Number::GetPoryadok(float key)
{
	int count = 0;
	while (abs(int(key)) > 0) {
		key=key / 10;
		count++;
	}
	return count;
}
void Number::SetPoryadok(int value)
{
	poryadok = value;
}
float Number::GetMant(float key)
{
	float floatpart = key;	
	float b;
	floatpart = modf(floatpart, &b);
	return floatpart;
}
void Number::SetMant(const float value)
{
	mant = value;
}
void Number::Show()
{
	cout << "\nЧисло: " << stroka;
	cout << "\nМантисса: " << mant;
	cout << "\nПорядок: " << poryadok << endl;
}
Number::Number(float value, int poryad, float mantissa)
{
	SetStroka(value);
	poryad=GetPoryadok(value);
	SetPoryadok(poryad);
	mantissa = GetMant(value);
	SetMant(mantissa);
	Show();
}
Number::Number(const Number& other)
{
	this->stroka = other.stroka;
	this->poryadok = other.poryadok;
	this->mant = other.mant;
}