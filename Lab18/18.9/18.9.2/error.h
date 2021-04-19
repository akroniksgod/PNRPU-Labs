#pragma once
#include <iostream>
#include <string>
using namespace std;
class error
{
	string str;
public:
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};