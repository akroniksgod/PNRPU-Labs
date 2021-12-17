#include <iostream>
#include <cmath>
using namespace std;

int main()
{    
    setlocale(LC_ALL, "Ru");
    double distance, r1, r2, x01, y01, x02, y02;
    cout << "Введите центр первой окружности (x01; y01) и радиус r1: ";
    cin >> x01 >> y01 >> r1;
    cout << "Введите центр второй окружности (x02; y02) и радиус r2: ";
    cin >> x02 >> y02 >> r2;
    
    distance = pow(pow(x02 - x01, 2) + pow(y02 - y01, 2), 0.5);
    if ((x01 == x02) && (y01 == y02) && (r1 == r2))
        cout << "Окружности совпадают\n";
    else
    {
        if (abs(r1 - r2) < distance && r1 + r2 > distance)
            cout << "Окружности имеют две общие точки\n";
        else if (r1 + r2 == distance)
            cout << "Окружности имеют одну общую точку (внешнее касание)\n";
        else if (abs(r1 - r2) == distance)
            cout << "Окружности имеют одну общую точку (внутреннее касание)\n";
        else 
            cout << "Нет общих точек\n";
    }
}