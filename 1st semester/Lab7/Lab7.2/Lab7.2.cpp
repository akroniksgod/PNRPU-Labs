#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdarg>
using namespace std;

void substract_dates(int day1, int mon1, int yea1, int day2, int mon2, int yea2);
void days(int datesCount, ...);
string insert_date(int dateNumber);

int main()
{
    setlocale(LC_ALL, "ru");
    string date1, date2, date3, date4, date5, date6, date7;
    
    date1 = insert_date(1);
    date2 = insert_date(2);
    days(3, date1, date2);

    date3 = insert_date(3);   
    date4 = insert_date(4);
    date5 = insert_date(5);    
    days(5, date3, date4, date1, date2);

    date6 = insert_date(6);
    date7 = insert_date(7);
    days(8, date5, date6, date7, date3, date4, date1, date2);
}

void days(int datesCount, ...)
{
    int day1, mon1, yea1;
    int day2, mon2, yea2;
    int day3, mon3, yea3;
    int day4, mon4, yea4;
    int day5, mon5, yea5;
    int day6, mon6, yea6;
    int day7, mon7, yea7;
    string date1, date2, date3, 
        date4, date5, date6, date7;
    va_list vl;
    va_start(vl, datesCount);
    
    date1 = va_arg(vl, string);
    date2 = va_arg(vl, string);

    if (datesCount == 5)
    {
        date3 = va_arg(vl, string);
        date4 = va_arg(vl, string);
    }
    else if (datesCount == 8)
    {
        date5 = va_arg(vl, string);
        date6 = va_arg(vl, string);
        date7 = va_arg(vl, string);
    }
    
    day1 = stoi(date1.substr(0, 2));
    mon1 = stoi(date1.substr(3, 2));
    yea1 = stoi(date1.substr(6, 2));

    day2 = stoi(date2.substr(0, 2));
    mon2 = stoi(date2.substr(3, 2));
    yea2 = stoi(date2.substr(6, 2));

    substract_dates(day1, mon1, yea1, day2, mon2, yea2);            
    cout << "Для дат: " << date1 << " и " << date2 << endl;

    if (datesCount >= 5)
    {
        day3 = stoi(date3.substr(0, 2));
        mon3 = stoi(date3.substr(3, 2));
        yea3 = stoi(date3.substr(6, 2));

        day4 = stoi(date4.substr(0, 2));
        mon4 = stoi(date4.substr(3, 2));
        yea4 = stoi(date4.substr(6, 2));

        substract_dates(day3, mon3, yea3, day4, mon4, yea4);
        cout << "Для дат: " << date3 << " и " << date4 << endl;

        if (datesCount == 8)
        {
            day5 = stoi(date5.substr(0, 2));
            mon5 = stoi(date5.substr(3, 2));
            yea5 = stoi(date5.substr(6, 2));

            day6 = stoi(date6.substr(0, 2));
            mon6 = stoi(date6.substr(3, 2));
            yea6 = stoi(date6.substr(6, 2));

            day7 = stoi(date7.substr(0, 2));
            mon7 = stoi(date7.substr(3, 2));
            yea7 = stoi(date7.substr(6, 2));
            
            substract_dates(day5, mon5, yea5, day6, mon6, yea6);
            cout << "Для дат: " << date5 << " и " << date6 << endl;

            substract_dates(day6, mon6, yea6, day7, mon7, yea7);
            cout << "Для дат: " << date6 << " и " << date7 << endl;
        }
    }
    va_end(vl);
}

void substract_dates(int day1, int mon1, int yea1, int day2, int mon2, int yea2)
{
    int sub_d, sub_m, sub_y;

    sub_d = day1 - day2;
    sub_m = mon1 - mon2;
    sub_y = yea1 - yea2;

    int result = sub_d + sub_m * 30 + sub_y * 365;
    if (result < 0)
        result *= -1;

    cout << endl << "Разница составляет " << result << " дня(ей)" << endl;
}

string insert_date(int dateNumber)
{
    string correctSymbols = "0123456789.", str = "";
    bool correctStr = true;
    do
    {
        cout << "Ввести " << dateNumber << " дату: ";
        cin >> str;
        if (str.length() == 8)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (correctSymbols.find(str[i]) == -1)
                    correctStr = false;
            }
        }
        else
            correctStr = false;
    } while (!correctStr);
    return str;
}