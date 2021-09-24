#include "Pair.h"
int SafeInput(bool strict = true) {
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ���������� �����!" << endl;
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
	return (out << "(" << t.first << "," << t.second << ")");
}
istream& operator>>(istream& in, Pair& t)
{
	cout << "������ ����� ����: ";
	in >> t.first;
	cout << "������ ����� ����: ";
	in >> t.second;
	return in;
}
Pair::Pair() {
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
	cout << "������ ����� ����: ";
	fir = SafeInput(true);
	return fir;
}
int Pair::GetSecond()
{
	int sec;
	cout << "������ ����� ����: ";
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
	cout << "(" << first << "," << second << ")" << endl;
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