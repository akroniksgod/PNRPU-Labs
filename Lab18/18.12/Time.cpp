#include "Time.h"
using namespace std;
int SafeInput(bool strict)
{
	int result;
	while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0) || (result > 60)) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число!" << endl;
	}
	cin.get();
	return result;
}
Time::Time() {
	mins = 0; secs = 0;
}
Time::Time(int minute, int second)
{
	SetMins(minute);
	SetSecs(second);
}
Time::~Time() {
}
int Time::GetMins()
{
	int minutes;
	cout << "¬ведите минуты >";
	minutes = SafeInput(true);
	return minutes;
}
int Time::GetSecs()
{
	int seconds;
	cout << "¬ведите секунды >";
	seconds = SafeInput(true);
	return seconds;
}
void Time::SetMins(int value)
{
	mins = value;
}
void Time::SetSecs(int value)
{
	secs = value;
}
void Time::Show()
{
	cout << "\n\n" << mins << ":" << secs;
}
Time Time::operator+(const Time& t)
{
	int temp1 = mins * 60 + secs;
	int temp2 = t.mins * 60 + t.secs;
	Time p;
	p.mins = (temp1 + temp2) / 60;
	p.secs = (temp1 + temp2) % 60;
	return p;
}
bool operator==(const Time& t1, const Time& t2)
{
	return (t1.mins == t2.mins && t1.secs == t2.secs);
}
bool operator!=(const Time& t1, const Time& t2)
{
	return (!(t1.mins == t2.mins && t1.secs == t2.secs));
}
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.mins << ":" << t.secs);
}
istream& operator>>(istream& in, Time& t)
{
	cout << "¬ведите минуты >";
	in >> t.mins;
	cout << "¬ведите секунды >";
	in >> t.secs;
	return in;
}