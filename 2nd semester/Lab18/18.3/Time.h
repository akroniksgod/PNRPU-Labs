#pragma once
#include<iostream>
using namespace std;
class Time {
	int mins, secs;
public:
	Time();
	Time(int minute, int second);
	~Time();
	int GetMins();
	int GetSecs();
	void SetMins(int value);
	void SetSecs(int value);
	void Show();	
	Time operator+(const Time&t);
	friend bool operator==(const Time&t1, const Time&t2);
	friend bool operator!=(const Time& t1, const Time& t2);
	friend ostream& operator<<(ostream&out, const Time&t);
	friend istream& operator>>(istream& in, Time& t);
};