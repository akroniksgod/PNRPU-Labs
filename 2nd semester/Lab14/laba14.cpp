#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;
enum Poisk {
	PRYAM = 1,
	KNUT,
	BOERMUR
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
		string names[] = { "Aleksadr", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "Valentin", "Mark" };
		string secnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
		string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
		fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		BirthDate.Day = 1 + rand() % 30;
		BirthDate.Month = 1 + rand() % 12;
		BirthDate.Year = 1000 + rand() % 1000;
		tel = 7900000000 + rand() % 10000000000;
	}
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\nДата рождения: " << BirthDate.Day << "." << BirthDate.Month << "." << BirthDate.Year
			<< "\nТелефон: " << tel << endl;
	}
};
void ConvertData(vector<Human> spisok, int keyday, int keymon, int keyyear, string& list, string& key);
bool KnutMorrisPratt(int keyday, int keymon, int keyyear, int kol, vector<Human>spisok);
bool SearchinSubstrInString(int kol,vector<Human> spisok,int keyday,int keymon,int keyyear);
void CheckingResult(bool result);
bool BoyerMur(vector<Human> spisok, int keyday, int keymon, int keyyear);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");
	int kol = -1, method, keyday, keymon, keyyear, x;
	bool result = false;
	while (kol < 1) {
		cout << "Введите количество элементов >";
		cin >> kol;
	}
	vector<Human> spisok(kol);
	for (int i = 0; i < kol; i++) {
		spisok[i].Random();
		spisok[i].Show();
	}	
	cout << "\nКаким методом поиска воспользоваться? " << endl
		<< "1) Прямой поиск;" << endl
		<< "2) Поиск Кнута-Морриса-Пратта;" << endl
		<< "3) Поиск Бойера-Мура; " << endl << endl << ">";
	cin >> method;
	switch (method) {		
	case PRYAM:
		cout << "\nВведите ключ (дату) через точки в формате дд мм гггг через Enter >";
		cin >> keyday >> keymon >> keyyear;
		result = SearchinSubstrInString(kol, spisok, keyday, keymon, keyyear);
		CheckingResult(result);
		break;
	case KNUT:
		cout << "Введите ключ (дату) в формате дд мм гггг через Enter >";
		cin >> keyday >> keymon >> keyyear;
		result = KnutMorrisPratt(keyday, keymon, keyyear, kol, spisok);
		CheckingResult(result);
		break;
	case BOERMUR:
		cout << "\nВведите ключ (дату) через точки в формате дд мм гггг через Enter >";
		cin >> keyday >> keymon >> keyyear;
		result = BoyerMur(spisok, keyday, keymon, keyyear);
		CheckingResult(result);
		break;
	default:
		cout << "Ввод не корректен!" << endl;
		break;
	}
}
bool KnutMorrisPratt(int keyday, int keymon, int keyyear, int kol, vector<Human>spisok)
{
	bool result = false;
	string key, list;	
	ConvertData(spisok, keyday, keymon, keyyear, list, key);
	vector<int> pi(key.length());
	for (int j = 0, i = 1; i < key.length(); i++) {
		while ((j > 0) && (key[i] != key[j]))
			j = pi[j - 1];
		if (key[i] == key[j])
			j++;
		pi[i] = j;
	}
	for (int j = 0, i = 0; i < list.length(); ++i) {
		while ((j > 0) && (key[j] != list[i]))
			j = pi[j - 1];		
		j++;
		if (j == key.length())
			result = true;
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
bool SearchinSubstrInString(int kol, vector<Human> spisok, int keyday, int keymon, int keyyear)
{
	bool result = false;
	string list,key;	
	ConvertData(spisok, keyday, keymon, keyyear, list, key);
	for (int i = 0; i <= list.size() - key.size(); i++) {
		int j = 0;
		while (list[i + j] == key[j] && j < key.size()) j++;
		if (j == key.size()) result = true;
	}
	return result;
}
bool BoyerMur(vector<Human> spisok, int keyday, int keymon, int keyyear)
{
	bool result = false;
	string list, key;
	ConvertData(spisok, keyday, keymon, keyyear, list, key);		
	int sl = list.size();
	int ssl = key.size();	
	int  i, Pos;
	int  BMT[256];
	for (i = 0; i < 256; i++) {
		BMT[i] = ssl;
	}
	for (i = ssl - 1; i >= 0; i--)
		if (BMT[(short)(key[i])] == ssl)
			BMT[(short)(key[i])] = ssl - i - 1;
	Pos = ssl - 1;
	while (Pos < sl)
		if (key[ssl - 1] != list[Pos])
			Pos = Pos + BMT[(short)(list[Pos])];
		else
			for (i = ssl - 2; i >= 0; i--) {
				if (key[i] != list[Pos - ssl + i + 1]) {
					Pos += BMT[(short)(list[Pos - ssl + i + 1])] - 1;
					break;
				}
				else
					if (i == 0)
						return result = true;					
			}		
	return result;
}
void ConvertData(vector<Human> spisok, int keyday, int keymon, int keyyear, string &list, string &key)
{		
	for (int i = 0; i < spisok.size(); i++) {
		string newLine = "";
		if (spisok[i].BirthDate.Day < 10) newLine += "0";
		newLine += to_string(spisok[i].BirthDate.Day);
		if (spisok[i].BirthDate.Month < 10) newLine += "0";
		newLine += to_string(spisok[i].BirthDate.Month);
		newLine += to_string(spisok[i].BirthDate.Year);
		list += newLine;
	}
	if (keyday < 10)
		key += "0";
	key += to_string(keyday);
	if (keymon < 10)
		key += "0";
	key += to_string(keymon);
	key += to_string(keyyear);	
}