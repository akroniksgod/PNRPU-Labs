#pragma once
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;
class Object
{
public:
	Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void);
	virtual void HandleEvent(TEvent& event) = 0;
};