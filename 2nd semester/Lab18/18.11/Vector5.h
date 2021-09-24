#pragma once
#include<iostream>
#include <queue>
using namespace std;
template <typename Type>
class Vector5
{
	queue<Type> container;
	int len;
public:
	Vector5() { len = 0; };
	Vector5(int n)
	{
		Type obj;
		for (int i = 0; i < n; i++) {
			obj = ((rand() % 100) * 0.1);
			container.push(obj);
		}
		len = container.size();
	}
	void Print()
	{
		queue<Type>temp;
		temp = container;
		while (!temp.empty()) {
			cout << temp.front() << "; ";
			temp.pop();
		}
		cout << endl;
	}
	Vector5 operator+(const Type newElement)
	{
		Vector5<Type>tmp;
		//queue<int>temp, temp2;
		for (int i = 0; i < len; i++) {
			container.front() += newElement;
			tmp.container.push(container.front());
			container.pop();
		}
		return tmp;
	}
	int get_size()
	{
		return len;
	}
	int FindAverageValue()
	{
		int length = len;
		queue<Type>tmp = container;
		int result = 0, count = 0;
		for (int i = 0; i < length; i++) {
			result += tmp.front();
			count++;
			tmp.pop();
		}
		result = result / count;
		return result;
	}
};