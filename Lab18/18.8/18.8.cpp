#include <iostream>
#include "Dialog.h"
int main()
{
    system("chcp 1251>nul");
    /* Print* a = new Print;
     a->Input();
     a->Show();

     Book* b = new Book;
     b->Input();
     b->Show();*/

     /*Vector vec(10);
     vec.push();
     vec.Show();
     vec.pop();*/
    cout << "Список команд: " << endl
        << " m - создать группу;" << endl
        << " + - добавить элемент в группу;" << endl
        << " - удалить элемент из группы;" << endl
        << " ? - вывести группы;" << endl
        << " q - выйти из программы" << endl
        << " / - вывести названия элементов группы" << endl;
    Dialog D;
    D.Execute();
}