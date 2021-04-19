#include "Time.h"
using namespace std;
Time::Time() {
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
	cin >> minutes;
	if (minutes > 60 || minutes < 0) {
		while (minutes > 60 || minutes < 0) {
			cout << "¬ведите минуты корректно >";
			cin >> minutes;
		}
	}
	return minutes;
}
int Time::GetSecs() 
{
	int seconds;
	cout << "¬ведите секунды >";
	cin >> seconds;
	if (seconds > 60 || seconds < 0) {
		while (seconds > 60 || seconds < 0) {
			cout << "¬ведите секунды корректно >";
			cin >> seconds;
		}
	}
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
	cout << "\n\n"<< mins << ":" << secs;
}
Time Time::operator+(const Time&t)
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
	return (t1.mins==t2.mins && t1.secs==t2.secs);
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