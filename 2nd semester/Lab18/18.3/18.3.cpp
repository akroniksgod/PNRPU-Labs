#include <iostream>
#include "Time.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    Time obj, tmp;
    int min, sec;
    min=obj.GetMins();
    sec = obj.GetSecs();
    obj.SetMins(min);
    obj.SetSecs(sec);
    cout << "\nВведите количество минут и секунд, которые необходимо добавить."<< endl;   
    min = tmp.GetMins();
    sec = tmp.GetSecs();
    Time obj2(min, sec);
    //проверка перегрузки оператора равенства
    if (obj == obj2)
        cout << "\nБыли введены те же минуты и секунды" << endl;
    else
        cout << "\nБыли введены другие значения" << endl;
    tmp = obj + obj2;    
    //tmp.Show();
    cout << "\nРезультат:  "<<tmp;
}