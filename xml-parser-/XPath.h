#pragma once
#include "Attribute.h"
#include "Element.h"
#include "Text.h"
class XPath
{
public:
	Element* getSiblingByTag(Element* root, String& name);
	void getTextNodesOfElement(Node* element);
	void printTextNodesOf(String& text, Element* root);
	void printTextNodesOfIndex(String& text, Element* root);
	void printIdAttributeOfIndex(String& text, Element* root);
};

