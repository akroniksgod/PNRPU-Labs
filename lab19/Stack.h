#pragma once
#include<iostream>
#include<ctime>
using namespace std;
template<class Type>
class Stack
{
	Type* root;
	int size;	
public:
	Stack();
	Stack(int s, Type element);	
	~Stack();	
	void push(Type& newElement);	
	void pop();	
	Type top();	
	bool empty();	
	void getStack();	
	int get_size();	
};
#include "Stack.cpp"