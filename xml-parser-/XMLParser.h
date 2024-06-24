#pragma once
#include <fstream>
#include <sstream>
#include "String.h"
#include "Attribute.h"
#include "Element.h"
#include "Text.h"

namespace {
	constexpr unsigned BUFFER_SIZE = 124;
}

class XMLParser {
private:
	Element* parseElement(String& buffer, size_t& pos);
	void parseAttributes(Element* element, String& buffer, size_t& pos);
	Text* parseText(String& buffer, size_t& pos);
	String parseName(String& buffer, size_t& pos);
	bool checkId(Element* element) const;
	void ensureId(Element* root);
	void setUniqueId(Element* root);
public:
	Element* parseXML(const String& filename);
	void print(Element* element);
};



