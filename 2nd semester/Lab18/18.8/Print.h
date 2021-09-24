#pragma once
#include "Object.h"
class Print :
    public Object
{
protected:
    string name, author;
public:
    Print();
    virtual ~Print() override;
    void Show();
    void Input();
    Print(string, string);
    Print(const Print&);
    string Get_name();
    string Get_author();
    void Set_name(string);
    void Set_author(string);
    Print& operator=(const Print&);
    void HandleEvent(TEvent& event);
};