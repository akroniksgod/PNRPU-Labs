#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Pair.h"
using namespace std;
void DeleteSmallerElements(char* fileName, int minFirst, double minSecond);
void IncreaseElement(char* fileName, int valueFirst, double valueSecond, int L);
void AddElements(char* fileName, vector<Pair> newElements, int position);
vector<Pair> ReadFile(string fileName);
void Print(vector<Pair> collection);
int main()
{
    setlocale(LC_ALL, "rus");
    char vvod = '5';
    while (vvod != '0')
    {
        cout << "========================" << endl;
        cout << "0 - Выход" << endl;
        cout << "1 - Чтение файла" << endl;
        cout << "2 - Чтение с удалением" << endl;
        cout << "3 - Чтение с изменением" << endl;
        cout << "4 - Чтение с добавлением" << endl
            << "\n>";
        cin >> vvod;

        char path[] = "input.txt";
        vector<Pair> pairs;
        switch (vvod)
        {
        case '1':
        {
            // ===reading===
            cout << "Чтение из файла без изменений" << endl;
            pairs = ReadFile(path);
        } break;
        case '2':
        {
            // ===deleting===
            cout << "Чтение из файла с удалением элементов меньше 3" << endl;
            DeleteSmallerElements(path, 3, 3);
            pairs = ReadFile(path);
        } break;
        case '3':
        {
            // ===changing===
            int f;
            double s;
            cout << "Введите пару, которую нужно увеличить" << endl;
            cin >> f >> s;
            cout << "Чтение из файла с увеличением элементов на 2" << endl;
            IncreaseElement(path, f, s, 2);
            pairs = ReadFile(path);
        } break;
        case '4':
        {
            // ===appending===
            int f1, f2, ind = -1;
            double s1, s2;
            cout << "Введите 2 пары (int, double, int double)" << endl;
            cin >> f1 >> s1 >> f2 >> s2;
            pairs = ReadFile(path);
            while (ind < 0 || ind > pairs.size()) {
                cout << "Введите индекс" << endl;
                cin >> ind;
            }
            cout << "Чтение из файла с добавлением 2 элементов" << endl;
            vector<Pair> newElements = { Pair(f1, s1), Pair(f2, s2) };
            AddElements(path, newElements, ind);
            pairs = ReadFile(path);
        } break;
        }
        Print(pairs);
    }
}
void Print(vector<Pair> collection)
{
    for (int i = 0; i < collection.size(); i++) {
        cout << "Pair " << i << endl;
        cout << collection[i];
    }
}
vector<Pair> ReadFile(string fileName)
{
    vector<Pair> res; // резултирующий вектор
    ifstream streamR;
    streamR.open(fileName);

    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            res.push_back(element);
        }
    }
    streamR.close();
    return res;
}
void AddElements(char* fileName, vector<Pair> newElements, int position)
{
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    int count = 0; // счетчик считанных элементов
    if (0 == position) {
        // добавление элементов в выходной поток
        for (int i = 0; i < newElements.size(); i++) {
            streamW << newElements[i];
        }
    }
    while (!streamR.eof())
    {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            streamW << element;
            count++;
            // проверка позиции для вставкиы
            if (count == position) {
                // добавление элементов в выходной поток
                for (int i = 0; i < newElements.size(); i++) {
                    streamW << newElements[i];
                }
            }
        }
    }
    streamR.close();
    streamW.close();
    remove(fileName);
    rename("temp.txt", fileName);
}
void IncreaseElement(char* fileName, int valueFirst, double valueSecond, int L)
{
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        if (element != Pair()) {
            // проверка элемента на условия для увеличения
            if (element.GetFirstElement() == valueFirst && element.GetSecondElement() == valueSecond)
            {
                element.SetFirst(element.GetFirstElement() + L);
                element.SetSecond(element.GetSecondElement() + L);
            }
            streamW << element;
        }
    }
    streamR.close();
    streamW.close();
    remove(fileName);
    rename("temp.txt", fileName);
}
void DeleteSmallerElements(char* fileName, int minFirst, double minSecond)
{
    // открытие файлов на чтение и запись
    ifstream streamR;
    streamR.open(fileName);
    ofstream streamW;
    streamW.open("temp.txt");

    // чтение всего файла
    while (!streamR.eof()) {
        Pair element;
        streamR >> element;
        // проверка на последнюю строку
        if (element != Pair()) {
            // проверка условия удаления элемента
            if (element.GetFirstElement() >= minFirst || element.GetSecondElement() >= minSecond) {
                streamW << element;
            }
        }
    }
    // закрытие потоков
    streamR.close();
    streamW.close();
    // удаление старого файла и замещение его новым
    remove(fileName);
    rename("temp.txt", fileName);
}