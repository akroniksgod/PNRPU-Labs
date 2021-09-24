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
	cout << "�������� ��������: ";
	getline(cin, s);
	char code = s[0];
	if (OptInt.find(code) != -1) {
		event.what = evMessage;
		switch (code) {
		case 'm': { event.command = cmMake; } break;//������� ������
		case '+': { event.command = cmAdd; } break;//�������� ������ � ������
		case '-': { event.command = cmDel; } break;//������� ������ �� ������
		case '?': { event.command = cmShow; } break;//�������� ������
		case 'q': { event.command = cmQuit; } break;//����� ������
		case '/': { event.command = cmGet;  } break;
		}
		if (s.length() > 1) {
			string param = s.substr(1, s.length() - 1);
			int Number = atoi(param.c_str());//�������������� ��������� � �����			
			event.a = Number;//���������� � ���������
		}
	}
	else event.what = evNothing;//������ �������	
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
		case cmMake://�������� ������
		{
			int Size = event.a;//������ ������
			beg = new Object * [Size];//��������� ������ ��� ������ ����������
			size = Size;
			current = 0;
			ClearEvent(event);
		}break;
		case cmAdd://����������
		{
			push();
			ClearEvent(event);
		}break;
		case cmDel://��������
		{
			pop();
			ClearEvent(event);
		}break;
		case cmShow://��������
		{
			Show();
			ClearEvent(event);
		}break;
		case cmQuit://�����
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
	event.what = evNothing;//������ �������
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