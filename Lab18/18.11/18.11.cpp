#include"Time.h"
#include"Vector.h"
#include <deque>
#include <queue>
#include <ctime>
#include "Vector5.h"
int SafeInput1(bool strict);
template <typename T>
void PrintDeque(deque<T> dq);
void Problem1()
{
    deque<int> dq;
    cout << "Введите размер двунаправленной очереди: ";
    int size = SafeInput1(true);
    for (int i = 0; i < size; i++) {
        dq.push_back(rand() % 100);
    }
    PrintDeque(dq);
    cout << "Удаление последнего элемента" << endl;
    dq.pop_back();
    PrintDeque(dq);
    cout << "Удаление первого элемента" << endl;
    dq.pop_front();
    PrintDeque(dq);
}
void Problem2()
{
    Time obj;
    int tmp = obj.GetMins();
    obj.SetMins(tmp);
    tmp = obj.GetSecs();
    obj.SetSecs(tmp);
    deque<Time>dq;
    cout << "Введите размер двунаправленной очереди: ";
    int size = SafeInput1(true);
    for (int i = 0; i < size; i++) {
        dq.push_back(obj);
    }
    PrintDeque(dq);
    cout << "Удаление последнего элемента" << endl;
    dq.pop_back();
    cout << "newSize=" << dq.size() << endl;
    PrintDeque(dq);
}
Vector<int> AddingMaxValue(Vector<int>intVec)
{
    int max = intVec[0];
    for (int i = 0; i < intVec.get_size(); i++) {
        if (max < intVec[i]) {
            max = intVec[i];
        }
    }
    cout << "Max=" << max<< endl;
    intVec.push_back(max);
    return intVec;
}
void Problem3()
{
    cout << "Введите размер контейнера: ";
    int size = SafeInput1(true);
    Vector<int> intVec(size, 0);
    cout << intVec;
    intVec = AddingMaxValue(intVec);
    cout << intVec;
}
void PrintQueue(queue<int>& line);
void Problem4()
{
    cout << "Введите размер очереди: ";
    int size = SafeInput1(true);
    queue<int> line;
    queue<int>temp;
    for (int i = 0; i < size; i++) {
        line.push(rand() % 100);
    }
    PrintQueue(line);
    cout << "\nВведите ключ, по которому надо удалить элемент: ";
    int key = SafeInput1(true);
    for (int i = 0; i < size; i++) {
        if (line.front() != key) {
            temp.push(line.front());
        }
        line.pop();
    }
    line = temp;
    PrintQueue(line);
}
void Problem5()
{
    cout << "Введите размер контейнера: ";
    int size = SafeInput1(true);
    Vector5<int> intVec(size);
    //Vector5<char> charVec(size);
    //Vector5<double> doubleVec(size);
    intVec.Print();
    //charVec.Print();
    //doubleVec.Print();
    int n = intVec.FindAverageValue();
    cout << "Среднее арифметическое: " << n << endl;
    intVec = intVec + n;
    cout << "Изменённый контейнер" << endl;
    intVec.Print();
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));
    int vvod = 6;
    while (vvod != 0) {
        cout << "\nКакое задание?" << endl
            << "1) " << endl
            << "2) " << endl
            << "3) " << endl
            << "4) " << "\n"
            << "5)" << endl
            << "0) Выход из меню" << "\n\n" << ">";
        cin >> vvod;
        switch (vvod)
        {
        case 1:
        {
            Problem1();
        }
        break;
        case 2:
        {
            Problem2();
        }
        break;
        case 3:
        {
            Problem3();
        }
        break;
        case 4:
        {
            Problem4();
        }
        break;
        case 5:
        {
            Problem5();
        }
        break;
        default:
            if (vvod != 0)
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
template <typename T>
void PrintDeque(deque<T> dq)
{
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << "; ";
    }
    cout << endl;
}
void PrintQueue(queue<int>& line)
{
    queue<int>temp;
    temp = line;
    while (!temp.empty()) {
        cout << temp.front() << "; ";
        temp.pop();
    }
    cout << endl;
}