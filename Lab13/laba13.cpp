#include <iostream>
using namespace std;
int doska[8][8];
bool try_ferz(int i);
void set_ferz(int i, int j);
void delete_ferz(int i, int j);
int main()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			doska[i][j] = 0;
		}
	}
	try_ferz(0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (doska[i][j] == -1) cout << "X "; // ферзь 
			else cout << "O "; // пустая клетка 
		}
		cout << endl;
	}
}
bool try_ferz(int i)
{
	bool result = false;
	for (int j = 0; j < 8; j++) { // итерирование по КЛЕТКАМ строки
		if (doska[i][j] == 0) { // поиск клетки, находящейся не под атакой ферзей		
			set_ferz(i, j); // вызов функции постановки ферзя И обозначения клеток, которые он бьет
			if (i == 7) // достижение последней строки шахматной доски (от 0 до 7)
				result = true; // изменение значения result для досрочного выхода из цикла на посл. строке доски после постановки ферзя
			else if (!(result = try_ferz(i + 1)))
				delete_ferz(i, j); /* для отката (удаления ферзя на предыд. строке еще для перехода на строку выше */
		}
		if (result == true)
			break; // досрочный выход из цикла после постановки ферзя на посл. строке доски		
	}
	return result;
}
void set_ferz(int i, int j)
{
	for (int x = 0; x < 8; x++) {
		doska[x][j]++; // По вертикали 
		doska[i][x]++; // По горизонтали 		
		int dia = j - i + x;
		if (dia >= 0 && dia < 8) {
			doska[x][dia]++;
		}
		dia = j + i - x;
		if (dia >= 0 && dia < 8)
			doska[x][dia]++;
		doska[i][j] = -1; // Ставим ферзя 
	}
}
void delete_ferz(int i, int j)
{
	for (int x = 0; x < 8; x++) {
		doska[x][j]--; // По вертикали 
		doska[i][x]--; // По горизонтали 		
		int dia = j - i + x;
		if (dia >= 0 && dia < 8) {
			doska[x][dia]--;
		}
		dia = j + i - x;
		if (dia >= 0 && dia < 8)
			doska[x][dia]--;
		doska[i][j] = 0;
	}
}