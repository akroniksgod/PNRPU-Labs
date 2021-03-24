#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    int size;
    cout << "Введите размер стека ";
    cin >> size;
    if (size < 1) {
        while (size < 1) {
            cout << "Введите размер стека корректно!";
            cin >> size;
        }
    }
    int vvod=5;    
    while (vvod != 0) {
        cout << "\n\nКакой стек? " << endl
            << "1) int" << endl
            << "2) float" << endl
            << "3) double" << endl
            << "4) char" << "\n"
            << "0) Выход из меню"<< endl<< ">" ;
        cin >> vvod;
        switch (vvod)
        {
        case 1:
        {
            int element;
            Stack<int> first(size, 0);
            first.getStack();
            cout << "\nВведите элемент в стек ";
            cin >> element;
            first.push(element);
            cout << "\ntop()=" << first.top() << endl;
            first.getStack();
            //int length = first.get_size();
            //for (int i=0; i< length; i++)
            first.pop();
            first.getStack();
            first.empty() ? cout << "\nTHE STACK IS EMPTY" : cout << "\nTHE STACK IS NOT EMPTY";
        }
        break;
        case 2:
        {
            float element;
            Stack<float> second(size, 0.5);
            second.getStack();
            cout << "\nВведите элемент в стек ";
            cin >> element;
            second.push(element);
            cout << "\ntop()=" << second.top() << endl;
            second.getStack();
            //int length = second.get_size();
            //for (int i=0; i< length; i++)
            second.pop();
            second.getStack();
            second.empty() ? cout << "\nTHE STACK IS EMPTY" : cout << "\nTHE STACK IS NOT EMPTY";
        }
        break;
        case 3:
        {
            double element;
            Stack<double> third(size, 0.15625);
            third.getStack();
            cout << "\nВведите элемент в стек ";
            cin >> element;
            third.push(element);
            cout << "\ntop()=" << third.top() << endl;
            third.getStack();
            //int length = third.get_size();
            //for (int i=0; i< length; i++)
            third.pop();
            third.getStack();
            third.empty() ? cout << "\nTHE STACK IS EMPTY" : cout << "\nTHE STACK IS NOT EMPTY";
        }
        break;
        case 4:
        {
            char element;
            Stack<char> fourth(size, 'a');
            fourth.getStack();
            cout << "\nВведите элемент в стек ";
            cin >> element;
            fourth.push(element);
            cout << "\ntop()=" << fourth.top() << endl;
            fourth.getStack();
            //int length = fourth.get_size();
            //for (int i=0; i< length; i++)
            fourth.pop();
            fourth.getStack();
            fourth.empty() ? cout << "\nEMPTY" : cout << "\nNOT EMPTY";
        }
        break;
        default:
            if (vvod!=0)
            cout << "ERROR!";
            break;
        }
    }
    return 0;
}