#include"Time.h"
#include"Vector.h"
#include <ctime>
#include <iterator>
int SafeInput1(bool strict);
typedef map<int, int>TMap;
typedef TMap::iterator it;
TMap Make_map(int n);
void PrintMap(TMap arr);
int SearchingMaxElement(TMap arr)
{
    it i = arr.begin();
    int count = 0, index = 0, max = (*i).second;
    while (i != arr.end()) {
        if (max < (*i).second) {
            max = (*i).second;
            index = count;
        }
        i++;
        count++;
    }
    return index;
}
void Problem1()
{
    TMap array;
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    array = Make_map(size);
    PrintMap(array);
    int indexOfMaxEl = SearchingMaxElement(array);
    cout << "MAX=" << array[indexOfMaxEl] << endl;
    int tmp = array[indexOfMaxEl];
    int i = array.size();
    array.insert(make_pair(i, tmp));
    cout << "NEW MAP" << endl;
    PrintMap(array);
}
typedef map<int, Time>TMap2;
typedef TMap2::iterator it2;
TMap2 Make_map2(int size)
{
    Time element;
    TMap2 arr;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp = rand() % 60;//= element.GetMins();
        element.SetMins(tmp);
        tmp = rand() % 60;//element.GetSecs();
        element.SetSecs(tmp);
        arr.insert(make_pair(i, element));
    }
    return arr;
}
void PrintMap2(TMap2 arr);
TMap2 DeleteKey(TMap2 arr, Time key)
{
    it2 iter = arr.begin();
    int count = 0, index = 0;
    while (iter != arr.end()) {
        if ((*iter).second == key) {
            arr.erase(count);
            return arr;
        }
        iter++;
        count++;
    }
    return arr;
}
void Problem2()
{
    TMap2 array;
    it2 iter;
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    array = Make_map2(size);
    PrintMap2(array);
    Time key;
    cout << "Введите ключ, который необходимо удалить " << endl;
    int tmp = key.GetMins();//= element.GetMins();
    key.SetMins(tmp);
    tmp = key.GetSecs();//element.GetSecs();
    key.SetSecs(tmp);
    array = DeleteKey(array, key);
    cout << "NEW MAP" << endl;
    PrintMap2(array);
}
void Problem3()
{
    cout << "Введите размерность ассоциативного контейнера map: ";
    int size = SafeInput1(true);
    Vector<int> array(size);
    array.PrintMap();
    int avg = array.FindAverageValue();
    cout << "Среднее арифметическое = " << avg << endl << "NEW MAP" << endl;
    array + avg;
    array.PrintMap();
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
        switch (vvod)
        {
        case '1':
        {
            Problem1();
        }
        break;
        case '2':
        {
            Problem2();
        }
        break;
        case '3':
        {
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
TMap Make_map(int n)
{
    TMap arr;
    int element;
    for (int i = 0; i < n; i++) {
        element = rand() % 100;
        arr.insert(make_pair(i, element));
    }
    return arr;
}
void PrintMap(TMap arr)
{
    it i;
    int count = 0;
    cout << "==============================" << endl;
    for (i = arr.begin(); i != arr.end();) {
        cout << count << ": " << (*i).second << endl;
        count++;
        i++;
    }
    cout << "==============================" << endl;
}
void PrintMap2(TMap2 arr)
{
    it2 i;
    int count = 0;
    cout << "==============================" << endl;
    for (i = arr.begin(); i != arr.end();) {
        cout << count << ": " << (*i).second << endl;
        count++;
        i++;
    }
    cout << "==============================" << endl;
}