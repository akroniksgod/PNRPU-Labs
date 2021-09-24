#pragma once
#include<iostream>
using namespace std;
class Time {
protected:
	int mins, secs;
public:
	Time();
	Time(int minute, int second);
	~Time();
	int GetMins();
	int GetSecs();
	int getM() { return mins; };
	int getS() { return secs; };
	void SetMins(int value);
	void SetSecs(int value);
	void Show();
	int GetValueToComapare() { int result = secs + (mins * 60); return result; }
	friend bool operator >(Time& t1, Time& t2) { return (t1.GetValueToComapare() > t2.GetValueToComapare()); }
	friend bool operator <(Time& t1, Time& t2) { return (t1.GetValueToComapare() < t2.GetValueToComapare()); }
	Time operator+(const Time& t);
	Time& operator=(const Time& other)
	{
		if (this == &other)
			return *this;
		mins = other.mins;
		secs = other.secs;
		return *this;
	}
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1, const Time& t2);
	friend ostream& operator<<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);
};