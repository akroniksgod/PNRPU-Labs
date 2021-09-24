#pragma once
class Iterator
{
protected:
	int* element;
	friend class Vector;
public:
	Iterator();
	Iterator(const Iterator&it);
	~Iterator();
	void operator ++();
	void operator --();
	int& operator *() const;	
	bool operator == (const Iterator&it);
	bool operator !=(const Iterator& it);	
};