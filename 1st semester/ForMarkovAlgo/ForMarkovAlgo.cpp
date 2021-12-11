#include <iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");	
	string s;
	string ab = "ab";
	string ba = "ba";
	string ac = "ac";
	string ca = "ca";
	string cb = "cb";
	string bc = "bc";
	string symbolsToReject = "1234567890-=qwertyuiop[]sdfghjkl;'\zxvnm,./";
	bool foundIncorrectSymb;
	do
	{
		foundIncorrectSymb = false;
		cout << "Введите строку: ";
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if (symbolsToReject.find(s[i]) != -1)
				foundIncorrectSymb = true;
		}
	} while (foundIncorrectSymb);
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s.find("ba") != -1)
		{
			s.replace(s.find(ba), ba.size(), ab);
		}
		if (s.find("ca") != -1)
		{
			s.replace(s.find(ca), ca.size(), ac);
		}
		if (s.find("cb") != -1)
		{
			s.replace(s.find(cb), cb.size(), bc);
		}
	}
	cout << "Преобразованная строка:" << s;
}
