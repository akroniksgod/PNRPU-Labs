#include "Number.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include<cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int method;
	cout << "\n����������� �����: " << endl
		<< "\t������� ��������� ������:" << endl
		<< "\t  1) ������������� ����� ������;" << endl
		<< "\t  2) ������������� ����� �����������;" << endl
		<< "\t  3) ������������� ����� ����������� �����������;" << endl
		<< ">";
	cin >> method;
	if (method == 1)
	{
		Number first;
		float key = 0;
		int Por = 0;
		float mantissa = 0;
		key = first.GetStroka();
		first.SetStroka(key); //���� �����
		Por = first.GetPoryadok(key);
		first.SetPoryadok(Por);//��������� �������
		mantissa = first.GetMant(key);
		first.SetMant(mantissa);//��������� ��������	
		first.Show(); //����� �� �����
	}
	else if (method == 2) {
		float key;
		int Por = 0;
		float mantissa = 0;
		cout << "������� ����� (���� �������, �� ����� �����) >";
		cin >> key;
		Number Second(key, Por, mantissa);		
	}
	else if (method == 3) {
		float key;
		int Por = 0;
		float mantissa = 0;
		cout << "������� ����� (���� �������, �� ����� �����) >";
		cin >> key;
		cout << "\nThird2"<< endl;
		Number Third2(key, Por, mantissa);
		Number Third(Third2);
		cout << "\n���� ������������ � Third"<< endl;
		Third.Show();
	}
}