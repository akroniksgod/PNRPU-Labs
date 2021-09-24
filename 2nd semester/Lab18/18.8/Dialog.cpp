#include "Dialog.h"
Dialog::Dialog()
{
	EndState = 0;
}
Dialog::~Dialog()
{
}
void Dialog::GetEvent(TEvent& event)
{
	string OptInt = "m+-?q/";
	string s;
	cout << "¬вдедите операцию: ";
	getline(cin, s);
	char code = s[0];
	if (OptInt.find(code) != -1) {
		event.what = evMessage;
		switch (code) {
		case 'm': { event.command = cmMake; } break;//создать группу
		case '+': { event.command = cmAdd; } break;//добавить объект в группу
		case '-': { event.command = cmDel; } break;//удалить объект из группы
		case '?': { event.command = cmShow; } break;//показать группу
		case 'q': { event.command = cmQuit; } break;//конец работы
		case '/': { event.command = cmGet;  } break;
		}
		if (s.length() > 1) {
			string param = s.substr(1, s.length() - 1);
			int Number = atoi(param.c_str());//преобразование параметра в число			
			event.a = Number;//записываем в сообщение
		}
	}
	else event.what = evNothing;//пустое событие	
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing) {
			ClearEvent(event);
		}
	} while (!Valid());
	return EndState;
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
		{
			int Size = event.a;//размер группы
			beg = new Object * [Size];//выделение пам€ти под массив указателей
			size = Size;
			current = 0;
			ClearEvent(event);
		}break;
		case cmAdd://добавление
		{
			push();
			ClearEvent(event);
		}break;
		case cmDel://удаление
		{
			pop();
			ClearEvent(event);
		}break;
		case cmShow://просмотр
		{
			Show();
			ClearEvent(event);
		}break;
		case cmQuit://выход
		{
			EndExec();
			ClearEvent(event);
		}break;
		default: { Vector::HandleEvent(event); }
		}
	}
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//пустое событие
}
int Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else
		return 1;
}
void Dialog::EndExec()
{
	EndState = 1;
}