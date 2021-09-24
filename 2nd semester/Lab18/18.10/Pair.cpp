#include <iostream>
#include "Pair.h"
using namespace std;
Pair::Pair()
{
    _first = INT_MIN;
    _second = INT_MIN;
}
Pair::Pair(int first, double second)
{
    _first = first;
    _second = second;
}
int Pair::GetFirstElement()
{
    return _first;
}
double Pair::GetSecondElement()
{
    return _second;
}
void Pair::SetFirst(int first)
{
    _first = first;
}
void Pair::SetSecond(double second)
{
    _second = second;
}
Pair::~Pair()
{

}
Pair Pair::operator+(const int secondOperator)
{
    Pair res;
    res._first = this->_first + secondOperator;
    res._second = this->_second;
    return res;
}
Pair Pair::operator+(const double secondOperator)
{
    Pair res;
    res._first = this->_first;
    res._second = this->_second + secondOperator;
    return res;
}
bool Pair::operator!=(Pair secondOperand)
{
    return _first != secondOperand._first && _second != secondOperand._second;
}
istream& operator>>(istream& stream, Pair& element)
{
    stream >> element._first;
    stream >> element._second;
    return stream;
}
ostream& operator<<(ostream& stream, Pair element)
{
    stream << element._first << endl;
    stream << element._second << endl;
    return stream;
}
