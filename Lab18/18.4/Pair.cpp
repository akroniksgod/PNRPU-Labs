#include "Pair.h"
int SafeInput(bool strict = true) {
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число!" << endl;
	}		
	return result;
}
Pair Pair::operator+(const Pair& t)
{	
	Pair r;
	r.first = first + t.first;
	r.second = second + t.second;
	return r;
}
ostream& operator<<(ostream& out, const Pair& t)
{
	return (out << "("<< t.first << "," << t.second<< ")");
}
istream& operator>>(istream& in, Pair& t)
{
	cout << "Первое число пары: ";	
	in >> t.first;	
	cout << "Второе число пары: ";
	in >> t.second;	
	return in;
}
Pair::Pair(){
}
Pair::Pair(int first, int second)
{
	this->first = first;
	this->second = second;
}
Pair::Pair(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;	
}
Pair::~Pair() {
}
int Pair::GetFirst()
{
	int fir;
	cout << "Первое число пары: ";	
	fir = SafeInput(true);
	return fir;
}
int Pair::GetSecond()
{
	int sec;
	cout << "Второе число пары: ";
	sec = SafeInput(true);
	return sec;
}
void Pair::SetFirst(int value)
{
	first = value;
}
void Pair::SetSecond(int value)
{
	second = value;
}
void Pair::Show()
{
	cout << "(" << first << "," << second << ")";
}
int Pair::GetF() 
{ 
	return first;
}
int Pair::GetS() 
{ 
	return second; 
}
Pair Pair::operator-(const Pair& t)
{
	Pair r;
	r.first = first - t.first;
	r.second = second - t.second;
	return r;
}
Complex::Complex()
{
}
Complex::~Complex()
{
}
Complex Complex::operator*(const Complex& t)
{
	Complex r;	
	r.real = first * t.first - second * t.second;
	r.imaginary = first * t.second + second * t.first;
	return r;
}
Complex ::Complex(Pair fir, Pair sec)
{
	SetReal(fir, sec);
	SetImag(fir, sec);
}
int Complex::getReal() 
{ 
	return real; 
}
int Complex::getImag() 
{ 
	return imaginary;
}
void Complex::SetReal(Pair a, Pair b)
{ 
	real = a.GetF() * b.GetF() - a.GetS() * b.GetS();
}
void Complex::SetImag(Pair a, Pair b)
{ 
	imaginary = a.GetF() * b.GetS() + a.GetS() * b.GetF(); 
}
void Complex::ShowComplex()
{ 
	cout << "(" << real << ", " << imaginary << "i)"; 
}