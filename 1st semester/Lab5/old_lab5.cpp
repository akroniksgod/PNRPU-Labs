#include <iostream>
using namespace std;

void print_array(int** pa, const int n);
bool sort_array(int**, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    cout << "16. Задан двумерный массив NxN. Разрешается" << "\n"
        << "произвольно переставлять элементы внутри любого" << "\n"
        << "столбца. Проверить, можно ли выполнив конечное" << "\n"
        << "количество перестановок в столбцах, расположить на" << "\n"
        << "побочной диагонали элементы так, чтобы они возрастали." << "\n\n";
    
    int n = 3; //размерность массива NxN
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Введите значение для элемента a[" << i << "][" << j << "] ";
            cin >> arr[i][j];
            cout << endl;
        }
    }
    print_array(arr, n);
    
    if (sort_array(arr, n) == 1)
        cout << "Расположить в возрастающем порядке возможно" << endl;
    else
        cout << "Расположить в возрастающем порядке невозможно" << endl;
}

bool sort_array(int** arr, int n) // проверка по условию
{
    //сортировка пузырьком элементов в столбцах по возрастанию
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int z = 0; z < n - 1; z++)
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[j][i] >= arr[j + 1][i])
                    swap(arr[j][i], arr[j + 1][i]);
            }
    }

    temp = arr[0][0];
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] > temp)
            {
                temp = arr[i][j];
                flag = 1;
                break;
            }
        }
        if (!flag)
            return false;
        flag = 0;
    }
    return true;
}

void print_array(int** arr, const int n) //печать массива в консоль
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}