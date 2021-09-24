#pragma once
#include "Print.h"
class Book :
    public Print
{
protected:
    int pages;
    string office;
public:
    Book();
    Book(int, string);
    Book(const Book&);
    ~Book();
    void Input();
    void Show();
    int Get_pages();
    string Get_office();
    Book& operator=(const Book&);
};