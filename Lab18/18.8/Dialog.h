#pragma once
#include "Vector.h"
#include "Event.h"
class Dialog :
    public Vector
{
protected:
    int EndState;
public:
    Dialog();
    virtual ~Dialog();
    virtual void GetEvent(TEvent& event);//получить событие
    virtual int Execute();//главный цикл обработки событий
    virtual void HandleEvent(TEvent& event); //обработка
    virtual void ClearEvent(TEvent& event);//очистить событие
    int Valid();//проверка атрибута EndState
    void EndExec();//обработка события "конец работы"
};