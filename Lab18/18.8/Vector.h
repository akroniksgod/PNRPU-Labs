#pragma once
#include "Object.h"
class Vector {
protected:
    int size, current;
    Object** beg;
public:
    Vector();
    Vector(int n);
    ~Vector();
    void push();
    void pop();
    void Show();
    int operator ()();
    //friend ostream& operator<<(ostream& out, const Vector& t);
    void HandleEvent(TEvent& event);
};