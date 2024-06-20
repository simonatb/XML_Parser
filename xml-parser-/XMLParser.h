#pragma once
#include <fstream>
#include <sstream>
#include "String.h"
#include "Attribute.h"
#include "Element.h"
#include "Text.h"

namespace {
	constexpr char fileName[] = "test.xml";
}
class XMLParser {

public:
	std::stringstream& saveFileToStream();

};



