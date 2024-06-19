#pragma once
#include "Node.h"
#include "Attribute.h"

class Element : public Node
{
	MyString name;
	Attribute* firstAttribute;
	Node* firstChild;
public:
	Element(const MyString& name);
	~Element();

	void setName(const MyString& name);
	void setFirstAttribute(Attribute* firstAttribute);
	void setFirstChild(Node* firstChild);

	MyString getName() const;
	Attribute* getFirstAttribute() const;
	Node* getFirstChild() const;

	void addAttribute(Attribute* attribute);
	void addChild(Node* child);
	MyString toString()const override;
};



