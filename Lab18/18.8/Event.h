#pragma once
enum EVENTS {
	evNothing = 0, //пустое событие
	evMessage = 100//непустое событие
};
enum COMMANDS {
	cmMake = 1,//создать группу
	cmAdd, //добавить объект в группу
	cmDel, //удалить объект из группы
	cmShow,//вывести всю группу
	cmQuit,//выход
	cmGet//вывести атрибут всех объектов		
};
class TEvent
{
public:
	int what;
	union
	{
		int command;//код команды
		struct
		{
			int message;
			int a;//параметр команды
		};
	};
};