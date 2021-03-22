#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
struct Date {
	int Day, Month, Year;
};
struct Human {
	string fio;
	Date BirthDate;
	long long tel;
	void Show()
	{
		cout << "\nФИО: " << fio
			<< "\nДата рождения: " << BirthDate.Day << "." << BirthDate.Month << "." << BirthDate.Year
			<< "\nТелефон: " << tel << endl;
	}
	string key;
	void keyforming()
	{
		if (BirthDate.Day < 10)
			key += "0";
		key += to_string(BirthDate.Day);
		if (BirthDate.Month < 10)
			key += "0";
		key += to_string(BirthDate.Month);
		key += to_string(BirthDate.Year);
	}
	int Hash;
	void hashForming(int M)
	{
		float A = 0.45457;
		float tmp = stoi(key) * A;
		float intpart;
		float floatpart;
		floatpart = modf(tmp, &intpart);
		Hash = trunc((M * floatpart));
	}
};
struct HashTaB {
	vector<Human> human_list;
	string key;
	int Hash;
	void Add_list(Human person)
	{
		human_list.push_back(person);
	}
};
void InsertionSort(vector<HashTaB>& HashTable);
string ConvertKey(int Day, int Month, int Year);
vector<Human> MakeArr(int size);
void MakeHashTab(vector<HashTaB>& Table, vector<Human> spisok, int kol);
void Show(vector<HashTaB>& Table);
Human* Seeking(vector<HashTaB>& Table, string _key);
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Ru");
	int kol = -1, keyday, keymon, keyyear;
	while (kol < 1) {
		cout << "Введите количество элементов >";
		cin >> kol;
	}
	vector<Human> spisok = MakeArr(kol);
	vector<HashTaB>Table;
	MakeHashTab(Table, spisok, kol);
	Show(Table);
	string keyToFind;
	cout << "\n\nВведите ключ (дату) для поиска через Enter >";
	cin >> keyday >> keymon >> keyyear;
	cout << "=====================================" << endl;
	keyToFind = ConvertKey(keyday, keymon, keyyear);
	Human* element = Seeking(Table, keyToFind);
	cout << endl;
	if (element == NULL) {
		cout << "Такого элемента нет!!!!!!!!!!!!!!!!!!!";
	}
	else {
		cout << "Такой элемент есть." << endl;
		element->Show();
	}
	cout << "=====================================" << endl;
}
vector<Human> MakeArr(int size)
{
	string names[] = { "Aleksadr", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "Valentin", "Mark" };
	string secnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
	string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
	vector <Human> result;
	for (int i = 0; i < size; i++) {
		Human NewPerson;
		NewPerson.fio = names[rand() % 7] + " " + secnames[rand() % 6] + " " + thirdnames[rand() % 5];
		NewPerson.BirthDate.Day = 1 + rand() % 30;
		NewPerson.BirthDate.Month = 1 + rand() % 12;
		NewPerson.BirthDate.Year = 1000 + rand() % 1000;
		NewPerson.tel = 7900000000 + rand() % 10000000000;;
		result.push_back(NewPerson);
	}
	return result;
}
void MakeHashTab(vector<HashTaB>& Table, vector<Human> spisok, int kol)
{
	for (int i = 0; i < spisok.size(); i++) {
		HashTaB tmp;
		spisok[i].keyforming();
		spisok[i].hashForming(spisok.size());
		tmp.Hash = spisok[i].Hash;
		tmp.key = spisok[i].key;
		tmp.Add_list(spisok[i]);
		Table.push_back(tmp);
	}
	InsertionSort(Table);
	for (int i = 0; i < kol - 1;) {
		if (Table[i].Hash == Table[i + 1].Hash) {
			Table[i].human_list.push_back(Table[i + 1].human_list[0]);
			Table.erase(Table.begin() + i + 1);
			kol--;
		}
		else
			i++;
	}
}
string ConvertKey(int Day, int Month, int Year)
{
	string key1;
	if (Day < 10)
		key1 += "0";
	key1 += to_string(Day);
	if (Month < 10)
		key1 += "0";
	key1 += to_string(Month);
	key1 += to_string(Year);
	return key1;
}
void InsertionSort(vector<HashTaB>& HashTable)
{
	for (int i = 0; i < HashTable.size(); i++) {
		for (int j = i; j > 0 && HashTable[j - 1].Hash > HashTable[j].Hash; j--) {
			swap(HashTable[j - 1], HashTable[j]);
		}
	}
}
void Show(vector<HashTaB>& Table)
{
	for (int i = 0; i < Table.size(); i++) {
		cout << "\nХеш: " << Table[i].Hash << endl;
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			Table[i].human_list[j].Show();
		}
		if (Table[i].human_list.size() > 1)
			cout << "\nКоличество коллизий: " << Table[i].human_list.size() << endl;
		cout << "=====================================" << endl;
	}
}
Human* Seeking(vector<HashTaB>& Table, string _key)
{
	Human* element = NULL;
	for (int i = 0; i < Table.size(); i++) {
		for (int j = 0; j < Table[i].human_list.size(); j++) {
			if (Table[i].human_list[j].key == _key)
				element = &Table[i].human_list[j];
		}
	}
	return element;
}