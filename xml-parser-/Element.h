#pragma once
#include "Node.h"
#include "Attribute.h"

class Element : public Node
{
	String name/*=""*/;
	Attribute* firstAttribute;
	Node* firstChild;
public:
	Element(const String& name);
	~Element();

	void setName(const String& name);
	void setFirstAttribute(Attribute* firstAttribute);
	void setFirstChild(Node* firstChild);

	String getName()const;
	Attribute* getFirstAttribute() const;
	Node* getFirstChild() const;

	void addAttribute(Attribute* attribute);
	void addChild(Node* child);
	String toString()const override;
   
   
   
};



