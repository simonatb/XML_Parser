#pragma once
#include "String.h"
#include "Node.h"
class Attribute :public Node
{
	String name;
	String value;
	Attribute* next;
public:
	Attribute(const String& name, const String& value);
	~Attribute();
	String toString() const override;

	void setName(const String& name);
	void setValue(const String& value);
	void setNext(Attribute* next);
	String getName() const;
	String getValue() const;
	Attribute* getNext() const;
	
};


