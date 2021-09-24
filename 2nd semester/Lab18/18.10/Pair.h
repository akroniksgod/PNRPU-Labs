#pragma once
using namespace std;
class Pair
{
    int _first;
    double _second;
public:
    Pair();
    Pair(int first, double second);
    int GetFirstElement();
    double GetSecondElement();
    void SetFirst(int first);
    void SetSecond(double second);
    ~Pair();
    Pair operator+(const int secondOperator);
    Pair operator+(const double secondOperator);
    bool operator!=(Pair secondOperand);
    friend istream& operator>>(istream& stream, Pair& element);
    friend ostream& operator<<(ostream& stream, Pair element);
};