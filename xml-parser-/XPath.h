#pragma once
#include "Attribute.h"
#include "Element.h"
#include "Text.h"
class XPath
{
public:
	Element* getSiblingByTag(Element* root, String& name);
	void getTextNodesOfElement(Node* element);
	void getTextNodesOfAttribute(Attribute* element);
	//operator/
	void printTextNodesOf(String& text, Element* root);
	//operator[]
	void printTextNodesOfIndex(String& text, Element* root);
	//operator@
	void printIdAttributes(String& text, Element* root);
	//operator=
	void printAfterComparison(String& text, Element* root);
};

