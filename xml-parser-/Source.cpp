
#include <iostream>
#include <fstream>
#include <sstream>
#include "String.h"
#include "Attribute.h"
#include "Element.h"
#include "Text.h"
#include "XMLParser.h"

int main() {
    XMLParser test("test2.txt");
    Element* root = test.parseXML();
    test.print(root);
    
}

    