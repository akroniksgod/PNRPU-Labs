#ifndef _STACK_CPP_
#define _STACK_CPP_
#include "Stack.h"
#include <assert.h>
template<class Type>
Stack<Type>::Stack()
{
}
template<class Type>
Stack<Type>::Stack(int s, Type element)
{
	size = s;
	root = new Type[size];
	for (int i = 0; i < size; i++) {
		root[i] = rand() % 100;
	}
}
template<class Type>
Stack<Type>::~Stack()
{
	delete[] root;
}
template<class Type>
void Stack<Type>::push(Type& newElement)
{
	Type* temp = new Type[size + 1];
	for (int i = 0; i < size; i++) {
		temp[i] = root[i];
	}
	delete[] root;
	temp[size++] = newElement;
	root = temp;
	temp = NULL;
}
template<class Type>
void Stack<Type>::pop()
{
	Type* temp = new Type[size - 1];
	for (int i = 0; i < size - 1; i++) {
		temp[i] = root[i];
	}
	size--;
	delete[] root;
	root = temp;
	temp = NULL;
	if (size == 0) root = NULL;
}
template<class Type>
bool Stack<Type>::empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}
template<class Type>
void Stack<Type>::getStack()
{
	cout << endl;
	for (int i = size - 1; i >= 0; i--) {
		cout << root[i] << "; ";
	}
}
template<class Type>
int Stack<Type>::get_size()
{
	return size;
}
template<class Type>
Type Stack<Type>::top()
{
	if (size != 0)
		return root[size - 1];
	else
		cout << "\nСтек пуст!" << endl;
}
#endif