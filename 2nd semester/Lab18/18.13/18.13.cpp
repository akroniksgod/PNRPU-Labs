#include "Time.h"
#include<algorithm>
#include <ctime>
#include <iterator>
#include <deque>
#include <functional>
#include <queue>
#include <map>
int SafeInput1(bool strict);
//overloading "max_element" as it doesn't work properly with class Time
template <typename iter>
iter max_element(iter &first, iter &last)
{    
    if (first == last) return last;
    iter largest = first;

    while (first != last) {
        if (*largest < *first)    // or: if (comp(*largest,*first)) for version (2)
            largest = first;
        first++;
    }
    return largest;
}
deque<Time> Make_Deque(int size);
void Print_Deque(deque<Time> line);
void Problem1()
{
    deque<Time> line, temp;
    cout << "Введите размерность двунаправленной очереди: ";
    int size = SafeInput1(true);
    line = Make_Deque(size);
    Print_Deque(line);    
    temp = line;        
    deque<Time>::iterator max, it=line.end();
    max = max_element(temp.begin(), temp.end());
    cout << *max << endl;
    line.insert(it, *max);
    Print_Deque(line);   
}
queue<Time> Make_Queue(int size);
void Print_Queue(queue<Time> line);
Time KeyForming(Time key);
queue<Time> DeleteTheKeyElement(queue<Time> line, Time key);
void Problem2()
{
    queue<Time> line,temp;    
    cout << "Введите размерность очереди: ";
    int size = SafeInput1(true);
    line = Make_Queue(size);
    Print_Queue(line);
    //forming key to delete it in the next function
    cout << "Введите ключ, который необходимо удалить из очереди!" << endl;
    Time key;    
    int tmp = key.GetMins();
    key.SetMins(tmp);
    tmp = key.GetSecs();
    key.SetSecs(tmp);
    line = DeleteTheKeyElement(line, key);    
    Print_Queue(line);
}
multimap <int, Time> Make_map(multimap <int, Time> map, int size);
void Print_Map(multimap <int, Time> map);
int FindAverageValue(multimap <int, Time> map);
void Problem3()
{
    multimap <int, Time> map;    
    cout << "Введите размерность ассоциативного контейнера multimap: ";
    int size = SafeInput1(true);
    map = Make_map(map, size);
    Print_Map(map);
    int avg = FindAverageValue(map);
    int minutes = avg / 60; //converting calculated value into minutes
    int seconds = avg % 60; //converting calculated value into seconds
    Time newElement(minutes, seconds);
    cout << "Среднее значение: " << newElement << endl;
    map.insert(make_pair(map.size(), newElement));
    Print_Map(map);
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    char vvod = '6';
    while (vvod != '0') {
        cout << "\nКакое задание?" << endl
            << "1) Задание 1;" << endl
            << "2) Задание 2;" << endl
            << "3) Задание 3;" << endl
            << "0) Выход из меню" << "\n\n" << ">";
        cin >> vvod;
        switch (vvod) {            
        case '1': {            
            Problem1();
        }
        break;
        case '2': {
            Problem2();
        }
        break;
        case '3': {
            Problem3();
        }
        break;
        default:
            if (vvod != '0')
                cout << "ERROR!";
            break;
        }
    }
    return 0;
}
int SafeInput1(bool strict)
{
    int result;
    while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное число!" << endl;
    }
    cin.get();
    return result;
}
deque<Time> Make_Deque(int size)
{
    deque<Time> temp;
    Time object;
    int tmp;
    for (int i = 0; i < size; i++) {
        object = KeyForming(object);
        temp.push_back(object);
    }
    return temp;
}
void Print_Deque(deque<Time> line)
{
    deque<Time> temp = line;
    for (int i = 0; i < line.size(); i++) {
        cout << temp.front() << "; ";
        temp.pop_front();
    }
    cout << endl;
}
queue<Time> Make_Queue(int size)
{
    queue<Time> temp;
    Time object;
    int tmp;    
    for (int i = 0; i < size; i++) {
        object = KeyForming(object);
        temp.push(object);
    }
    return temp;
}
void Print_Queue(queue<Time> line)
{
    queue<Time> temp = line;
    for (int i = 0; i < line.size(); i++) {
        cout << temp.front() << "; ";
        temp.pop();
    }
    cout << endl;
}
Time KeyForming(Time key)
{
    int tmp = rand() % 60;
    key.SetMins(tmp);
    tmp = rand() % 60;
    key.SetSecs(tmp);
    return key;
}
queue<Time> DeleteTheKeyElement(queue<Time> line, Time key)
{
    queue<Time> temp;
    int size = line.size();
    for (int i = 0; i < size; i++) {
        if (line.front() != key) {
            temp.push(line.front());
        }
        line.pop();
    }
    return temp;
}
multimap <int, Time> Make_map(multimap <int, Time> map, int size)
{
    Time obj;
    int tmp;
    for (int i = 0; i < size; i++) {
        obj = KeyForming(obj);
        map.insert(make_pair(i, obj));
    }
    return map;
}
void Print_Map(multimap <int, Time> map)
{
    multimap <int, Time>::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
        cout << (*i).second << "; ";
    }
    cout << endl;
}
int FindAverageValue(multimap <int, Time> map)
{
    int result = 0;
    multimap <int, Time>::iterator i;
    for (i = map.begin(); i != map.end(); i++) {
        result += (*i).second.GetValueToComapare(); //adding each samples converted into seconds 
    }
    result = result / map.size();
    return result;
}