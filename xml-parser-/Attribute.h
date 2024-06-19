#pragma once
#include "MyString.h"

class Attribute
{
	MyString name;
	MyString value;
	Attribute* next;
public:
	Attribute(const MyString& name, const MyString& value);
	~Attribute();
	MyString toString() const;

	void setName(const MyString& name);
	void setValue(const MyString& value);
	void setNext(Attribute* next);
	MyString getName() const;
	MyString getValue() const;
	Attribute* getNext() const;
};


