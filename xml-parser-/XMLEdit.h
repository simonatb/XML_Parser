#pragma once
#include "String.h"
#include "XMLParser.h"
class XMLEdit
{
public:
	void select(Element* root, int id, const String& key);
	void set(Element* root, int id, const String& key,const String& value);
	void children(Element* root, int id);
	void childrenNth(Element* root, int id, int n);
	void deleteAttribute(Element* root, int id, const String& key);
	void addNewChild(Element* root, int id);
};

