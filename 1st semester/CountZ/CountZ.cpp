#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    double z = 0, z1 = 0, b = 0;
    while (b < 1 || b >= 7)
    {
        cout << "Введите значение B от 1 до 8: ";
        cin >> b;
    }
    if (b >= 2 && b <= 7)
    {
        z = pow(b * 2.0 + (2 * pow((pow(b, 2) - 4), 0.5)), 0.5) / (pow((pow(b, 2) - 4), 0.5) + b + 2);
        z1 = 1 / (pow((b + 2), 0.5));
        cout << "Z=" << z << "; \n" << "Z1=" << z1 << "; \n";
    }
    else if (b == 1)
        cout << "Невозможно посчитать Z\n";
}