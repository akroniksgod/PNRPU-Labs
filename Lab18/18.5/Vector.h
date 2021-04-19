#pragma once
#include<iostream>
#include "Abstract.h"
using namespace std;
class Vector {
    int size, current;
    Abstract** beg;
public:
    Vector();
    Vector(int n);
    ~Vector();
    void push(Abstract* pointer);
    friend ostream& operator<<(ostream& out, const Vector& t);
};

