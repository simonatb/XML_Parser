#include <iostream>
#include <fstream>
#include <sstream>
#include "String.h"
#include "Attribute.h"
#include "Element.h"
#include "Text.h"
#include "XMLParser.h"
#include "XMLEdit.h"
#include "XPath.h"

int main() {
    String str1("person/address");
    String str2("person/occupation[0]");
    String str3("person[@id]");
    String str4("nameType");
    String str5("none");
    String str6("occupationType");

    XMLEdit edit;
    XPath path;
    XMLParser parser;

    Element* root = parser.parseXML("test2.txt");
    parser.print(root);
    std::cout << std::endl;
    path.printTextNodesOf(str1,root);
    std::cout << std::endl;
    path.printTextNodesOfIndex(str2, root);
    std::cout << std::endl;
    path.printIdAttributes(str3, root);
    std::cout << std::endl;

    edit.select(root, 1, str4);
    std::cout << std::endl;
    edit.deleteAttribute(root, 3, str6);
    edit.set(root, 0, str4, str5);
    edit.children(root, 2);
    std::cout << std::endl;
    edit.childrenNth(root, 2, 1);
    edit.addNewChild(root, 0);
    std::cout << std::endl;
    parser.print(root);
}
    