#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
using namespace std;
int WordsCount(string row, int WordsCount);
int main()
{
	setlocale(LC_ALL, "Ru");
	int n1 = -1, n2 = -2;
	char a = 'a';
	char c = 'c';
	bool flag = false;
	ifstream input("F1.txt");
	ofstream output("F2.txt");
	if (input.is_open()) {
		while (n1 <= 0 || n1>10) {
			cout << "Введите номер строки, откруда начинать сканирование: ";
			cin >> n1;
		}
		while (n2 <= 0 || n2>10 || n1 == n2) {
			cout << "Введите номер строки, которой заканчивать сканирование: ";
			cin >> n2;
		}
		string row;
		int numberOFrow = 1;
		while (!input.eof()) {
			getline(input, row);
			if (numberOFrow >= n1 && numberOFrow <= n2) {
				char first, last;
				for (int j = 0; j < 1; j++) {
					first = row[j];
				}
				for (int j = row.length(); j > (row.length() - 2); j--) {
					last = row[j];
				}
				if (first == a && last == c) {
					output << row << '\n';
					flag = true;
				}
			}
			numberOFrow++;
		}
		output.close();
	}
	else
		cout << "\nФайл не открыт! ";
	if (flag) {
		cout << "\nСтрока(-и) были перенесены! ";
		ifstream f2in("F2.txt");
		string row1;
		int Count = 0;
		getline(f2in, row1);
		cout << "\nВ файле F2 в первой строке " << WordsCount(row1, Count) << " слов." << endl;
		f2in.close();
	}
	else
		cout << "\nСтроки не были перенесены! ";
	input.close();
	return 0;
}
int WordsCount(string row, int Count)
{
	for (int i = 0; i < row.length(); i++) {
		while (row[i] == ' ')
			i++;
		while (row[i] != ' ' && row[i] != '\0' && row[i] != '\n')
			i++;
		Count++;
	}
	return Count;
}