#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
enum Poisk{
	LINEAR=1,
	PRYAM,
	INTERPOL
};
struct Date
{
	int Day, Month, Year;	
};
struct Human {
	string fio;
	Date BirthDate;
	long long tel;	
	void Random()
	{		
		string names[] = { "Aleksadr", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "Valentin", "Mark"};
		string secnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
		string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
		fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		BirthDate.Day =1 + rand() % 30;
		BirthDate.Month = 1 + rand() % 12;
		BirthDate.Year = 1000 + rand() % 1000;
		tel = 7900000000 + rand() % 10000000000;
	}
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\nДата рождения: " << BirthDate.Day << "." << BirthDate.Month << "." << BirthDate.Year
			<< "\nТелефон: " << tel<< endl;
	}
};
bool LinearSearch(vector<Human>spisok, int kol, int keyday, int keymon, int keyyear);
bool Interpolation(vector<Human>spisok, int kol, int keyday, int keymon, int keyyear);
bool SearchinSubstrInString(int kol, vector<Human>spisok, int keyday, int keymon, int keyyear);
void CheckingResult(bool result);
void Addition(vector<Human>& spisok, int& kol, int keyday, int keymon, int keyyear);
void Deletion(vector<Human>& spisok, int& kol,int keyday, int keymon,int keyyear);
void SaveToFile(vector<Human>& spisok);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");	
	int kol=-1,method, keyday, keymon, keyyear, x;	
	while (kol < 1) {
		cout << "Сколько элементов Вы хотите поместить в файл? >";
		cin >> kol;
	}
	vector<Human> spisok(kol);	
	for (int i = 0; i < kol; i++) {
		spisok[i].Random();
		spisok[i].Show();
	}
	cout << "\nХотите ли Вы записать изначальные данные в файл (0/1)? ";
	cin >> x;
	if (x==1) {
		string path = "F1.txt";
		ofstream out = ofstream();
		out.open(path, ofstream::app);
		out << "Изначальный масссив структур." << endl<< endl;
		SaveToFile(spisok);
		out << "=============================" << endl;
		out.close();
	}
	cout << "\nКаким методом поиска воспользоваться? " << endl
		<< "1) Линейный поиск;" << endl
		<< "2) Прямой поиск подстроки в строке;" << endl
		<< "3) Итерполяционный поиск; " << endl<< endl<< ">";
	cin >> method;
	switch (method) {
		bool result;		
	case LINEAR:		
		cout << "Введите ключ (дату) в формате дд мм гггг через Enter >";
		cin >> keyday >> keymon >> keyyear;		
		result =LinearSearch(spisok, kol, keyday, keymon, keyyear);
		CheckingResult(result);
		if (result) {			
			cout << "\n\nЧто бы Вы хотели выполнить: " << endl
				<< "1) Добавление элемента;" << endl
				<< "2) Удаление элемента; " << endl << ">";
			cin >> method;			
			switch (method)	{
			case 1:
				Addition(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			case 2:
				Deletion(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			default:
				cout << "Ввод не корректен!" << endl;
				break;
			}
		}
		break;
	case PRYAM:
		cout << "\nВведите ключ (дату) через точки в формате дд мм гггг через Enter >";		
		cin >> keyday >> keymon >> keyyear;		
		result = SearchinSubstrInString(kol, spisok, keyday, keymon, keyyear);
		CheckingResult(result);
		if (result) {
			cout << "\n\nЧто бы Вы хотели выполнить: " << endl
				<< "1) Добавление элемента;" << endl
				<< "2) Удаление элемента; " << endl << ">";
			cin >> method;					
			switch (method) {
			case 1:				
				Addition(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			case 2:				
				Deletion(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			default:
				cout << "Ввод не корректен!" << endl;
				break;
			}
		}
		break;
	case INTERPOL:				
		cout << "\nВведите ключ (дату) в формате дд мм гггг через Enter >";
		cin >> keyday >> keymon >> keyyear;		
		result = Interpolation(spisok, kol, keyday, keymon, keyyear);
		CheckingResult(result);
		if (result) {
			cout << "\n\nЧто бы Вы хотели выполнить: " << endl
				<< "1) Добавление элемента;" << endl
				<< "2) Удаление элемента; " << endl << ">";
			cin >> method;			
			switch (method)
			{
			case 1:
				Addition(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			case 2:
				Deletion(spisok, kol, keyday, keymon, keyyear);
				for (int i = 0; i < kol; i++) {
					spisok[i].Show();
				}
				cout << "\nХотите ли Вы записать изменённые данные в файл (0/1)? ";
				cin >> x;
				if (x==1) {
					string path = "F1.txt";
					ofstream out = ofstream();
					out.open(path, ofstream::app);
					out << "Изменённый масссив структур." << endl;
					SaveToFile(spisok);
					out << "=============================" << endl;
					out.close();
				}
				break;
			default:
				cout << "Ввод не корректен!" << endl;
				break;
			}
		}
		break;
	default:
		cout << "Ввод не корректен!" << endl;
		break;
	}	
}
bool LinearSearch(vector<Human>spisok, int kol,int keyday, int keymon, int keyyear)
{
	int ind = -1;
	bool result=false;
	for (int i = 0; i < kol && result == false; i++) {
		if (spisok[i].BirthDate.Day == keyday && spisok[i].BirthDate.Month == keymon && spisok[i].BirthDate.Year == keyyear) {
			result = true;
			ind = i;
		}
	}
	return result;
}
bool Interpolation(vector<Human>spisok,int kol,int keyday,int keymon,int keyyear)
{
	int ind;
	bool result = false, resd=false, resmon=false,resyear=false;
	vector<Date> dataspisok(kol);
	for (int i = 0; i < kol; i++) {
		dataspisok[i].Day = spisok[i].BirthDate.Day;
		dataspisok[i].Month = spisok[i].BirthDate.Month;
		dataspisok[i].Year = spisok[i].BirthDate.Year;
	}
	//sorting for a "day" principle
	for (int i = 0; i < kol; i++) {
		for (int j = i; j > 0 && dataspisok[j - 1].Day > dataspisok[j].Day; j--) {			
			swap(dataspisok[j - 1].Day, dataspisok[j].Day);
		}
	}
	//actual searching
	int mid, left=0, right = kol - 1;
	while (dataspisok[left].Day < keyday && dataspisok[right].Day > keyday) {
		mid = left + (keyday - dataspisok[left].Day) * (right - left) / (dataspisok[right].Day - dataspisok[left].Day);
		if (dataspisok[mid].Day < keyday)
			left = mid + 1;
		else if (dataspisok[mid].Day > keyday)
			right = mid - 1;		
	}
	if (dataspisok[left].Day == keyday) {
		ind = left;
		resd = true;
	}
	if (dataspisok[right].Day == keyday) {
		resd = true;
		ind = right;
	}
	if (resd==true) {
		if (keymon == dataspisok[ind].Month)
			resmon = true;
		if (keyyear == dataspisok[ind].Year)
			resyear = true;
	}
	else
		result = false;
	if (resd && resmon && resyear)
		result=true;	
	return result;
}
bool SearchinSubstrInString(int kol, vector<Human>spisok,int keyday,int keymon,int keyyear)
{
	bool result = false;		
	string list;
	for (int i = 0; i < spisok.size(); i++) {		
		string newLine = "";
		if (spisok[i].BirthDate.Day < 10) newLine += "0";
		newLine+= to_string(spisok[i].BirthDate.Day);
		if (spisok[i].BirthDate.Month < 10) newLine += "0";
		newLine+= to_string(spisok[i].BirthDate.Month);			
		newLine +=to_string(spisok[i].BirthDate.Year);
		list += newLine;
	}
	string substr;
	if (keyday < 10)
		substr += "0";	
	substr +=to_string(keyday);
	if (keymon < 10)
		substr += "0";
	substr += to_string(keymon);
	substr += to_string(keyyear);
	for (int i = 0; i <= list.size() - substr.size(); i++) {
		int j = 0;
		while (list[i + j] == substr[j] && j < substr.size()) j++;
		if (j == substr.size()) result=true;
	}
	return result;
}
void CheckingResult(bool result)
{
	if (result == true)
		cout << "\nДата была найдена!" << endl;
	else
		cout << "\nДата не была найдена!" << endl;
}
void Addition(vector<Human>& spisok, int& kol, int keyday, int keymon, int keyyear)
{
	int ind;
	bool result = false;
	for (int i = 0; i < kol && result == false; i++) {
		if (spisok[i].BirthDate.Day == keyday && spisok[i].BirthDate.Month == keymon && spisok[i].BirthDate.Year == keyyear) {
			result = true;
			ind = i;
		}
	}	
	vector<Human> spisok2(kol+1);
	for (int i = 0; i < ind; i++) {
		spisok2[i] = spisok[i];		
	}
	for (int i = ind; i < ind + 1; i++) {
		spisok2[i].Random();
	}
	kol++;
	for (int i = ind; i < kol-1; i++) {
		spisok2[i+1] = spisok[i];
	}
	spisok = spisok2;
}
void Deletion(vector<Human>& spisok, int& kol, int keyday, int keymon, int keyyear)
{
	int ind;
	bool result = false;
	for (int i = 0; i < kol && result == false; i++) {
		if (spisok[i].BirthDate.Day == keyday && spisok[i].BirthDate.Month == keymon && spisok[i].BirthDate.Year == keyyear) {
			result = true;
			ind = i;
		}
	}
	vector<Human> spisok2(kol - 1);
	for (int i = 0; i < ind; i++) {
		spisok2[i] = spisok[i];

	}
	kol--;
	for (int i = ind; i < kol; i++) {
		spisok2[i] = spisok[i+1];
	}
	spisok = spisok2;
}
void SaveToFile(vector<Human>& spisok)
{
	string path = "F1.txt";
	ofstream out = ofstream();
	out.open(path, ofstream::app);
	for (int i = 0; i < spisok.size(); i++) {
		out << "ФИО: " << spisok[i].fio << endl;
		out << "Дата рождения: " << spisok[i].BirthDate.Day;
		out << "." << spisok[i].BirthDate.Month;
		out << "." << spisok[i].BirthDate.Year << endl;
		out << "Телефон: " << spisok[i].tel << endl << endl;
	}
	out.close();
	cout << "Список сохранён в файл F1.txt" << endl;
}