#pragma once
enum EVENTS {
	evNothing = 0, //������ �������
	evMessage = 100//�������� �������
};
enum COMMANDS {
	cmMake = 1,//������� ������
	cmAdd, //�������� ������ � ������
	cmDel, //������� ������ �� ������
	cmShow,//������� ��� ������
	cmQuit,//�����
	cmGet//������� ������� ���� ��������		
};
class TEvent
{
public:
	int what;
	union
	{
		int command;//��� �������
		struct
		{
			int message;
			int a;//�������� �������
		};
	};
};