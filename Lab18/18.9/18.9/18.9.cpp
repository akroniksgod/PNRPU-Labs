#include "Vector.h"
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Ru");
    int size;
    try {
        cout << "Введите размер вектора: ";
        cin >> size;
        Vector first(size);
        cout << "До :: ";
        first.get_Vector();
        char choice;
        cout << "Удалить певый (1) или последний элемент (n)? ";
        cin >> choice;
        if (choice == '1') {
            first--;
        }
        else if (choice == 'n') {
            --first;
        }
        else
            throw 6;
        cout << "После :: ";
        first.get_Vector();
        cout << "Размер нового вектора: " << first() << endl;
        int index;
        cout << "По какому индексу выдать значение? ";
        cin >> index;
        cout << "\narr[" << index << "]=" << first[index] << endl;
    }
    catch (int) {
        cout << "\nОШИБКА" << endl;
    }
    return 0;
}