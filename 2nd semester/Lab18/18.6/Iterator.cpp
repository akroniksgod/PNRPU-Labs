#include "Iterator.h"
Iterator::Iterator()
{
	element = 0;
}
Iterator::Iterator(const Iterator& it)
{
	element = it.element;
}
Iterator::~Iterator()
{
}
void Iterator::operator++()
{
	++element;
}
void Iterator::operator--()
{
	--element;
}
int& Iterator::operator*() const
{
	return *element;
}
bool Iterator::operator==(const Iterator& it)
{
	return element==it.element;
}
bool Iterator::operator!=(const Iterator& it)
{
	return (!(element == it.element));
}