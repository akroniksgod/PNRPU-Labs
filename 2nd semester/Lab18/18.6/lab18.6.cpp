#include "Vector.h"
int SafeInput(bool strict);
int SafeInput2(bool strict);
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Ru");
    int size, n, index;
    cout << "Введите размер вектора: ";
    size = SafeInput(true);
    Vector first(size);
    first.get_Vector();
    cout << "first()=" << *(first.first())<< endl 
        << "last()=" << *(first.last()) << endl;
    cout << "Введите число, на которое нужно домножить вектор: ";
    n = SafeInput2(true);
    first* n;
    cout << first;
    cout << "Введите число, на которое нужно сдвинуть итератор влево: ";
    n = SafeInput(true);    
    first -= n;
    cout << "Доступ по какому индексу получить? ";
    index = SafeInput(true);
    try {
        cout << "array[" << index << "]=" << first[index] << endl;
    }
    catch (int) { cout << "\nINDEX ERROR"<< endl; }
}
int SafeInput(bool strict) {
    int result;
    while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное число!" << endl;
    }
    cin.get();
    return result;
}
int SafeInput2(bool strict) {
    int result;
    while (!(cin >> result) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное число!" << endl;
    }
    cin.get();
    return result;
}