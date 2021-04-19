#include "error.h"
#include "Vector.h"
#include <ctime>
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
            throw error("Был введён не верный символ!\n");
        cout << "После :: ";
        first.get_Vector();
        cout << "Размер нового вектора: " << first() << endl;
        int index;
        cout << "По какому индексу выдать значение? ";
        cin >> index;
        cout << "\narr[" << index << "]=" << first[index] << endl;
    }
    catch (error e) {
        e.what();
    }
    return 0;
}