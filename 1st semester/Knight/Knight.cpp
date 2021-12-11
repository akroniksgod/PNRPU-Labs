#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int m, n, x0, y0, x, y, t, tempX = 0, tempY = 0;
    cout << "Введите количество тестов: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Введите размерность доски: ";
        cin >> m >> n;
        if ((n >= 2) & (m >= 2) & ((n != 2) & (m != 2)))
        {
            cout << "Введите координаты коня(x0;y0): ";
            cin >> x >> y;
            int sum = 0;
            tempX = x;
            tempY = y;
            if (((x + 2) <= n) & ((y + 1) <= m))
            {
                sum++;
                x += 2;
                y += 1;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x + 1) <= n) & ((y + 2) <= m))
            {
                sum++;
                x += 1;
                y += 2;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x - 2) <= n) & ((y + 1) <= m) & (x - 2 > 0))
            {
                sum++;
                x -= 2;
                y += 1;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x - 1) <= n) & ((y + 2) <= m) & (x - 1 > 0))
            {
                sum++;
                x -= 1;
                y += 2;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x - 2) <= n) & ((y - 1) <= m) & (x - 2 > 0) & (y - 1 > 0))
            {
                sum++;
                x -= 2;
                y -= 1;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x - 1) <= n) & ((y - 2) <= m) & (x - 1 > 0) & (y - 2 > 0))
            {
                sum++;
                x -= 1;
                y -= 2;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x + 2) <= n) & ((y - 1) <= m) & (y - 1 > 0))
            {
                sum++;
                x += 2;
                y -= 1;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            if (((x + 1) <= n) & ((y - 2) <= m) & (y - 2 > 0))
            {
                sum++;
                x += 1;
                y -= 2;
                cout << "X=" << x << ";";
                cout << "y=" << y << ";\n";
                x = tempX;
                y = tempY;
            }
            cout << "Количество ходов: " << sum << "\n";
        }
        else
            cout << "Выполнить ход невозможно.";
    }
}