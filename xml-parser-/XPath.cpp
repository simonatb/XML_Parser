#include "XPath.h"

//Helper functions
int getCharPos(String& text, char ch) {
    for (size_t i = 0;i < text.length();i++) {
        if (text[i] == ch) {
            return i;
        }
    }
    return 0;
}

void separateString(String& first, String& second, String& text) {
    first = text.substr(0, getCharPos(text, '/'));
    second = text.substr(getCharPos(text, '/') + 1, text.length() - getCharPos(text, '/'));
}

int fromStringToNumber(String& text) {
    int number = 0;
    for (size_t i = 0; i < text.length(); i++) {
        number = number * 10 + (text[i] - '0');
    }
    return number;
}

int getIndex(String& text) {
    String number;
    int start = -1;
    int end = -1;

   
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == '[') {
            start = i;
        }
        else if (text[i] == ']') {
            end = i;
            break;
        }
    }

    if (start != -1 && end != -1 && end > start) {
        number = text.substr(start + 1, end - start - 1);
        text = text.substr(0, start);
    }
    else {
        return -1;
    }
    return fromStringToNumber(number);
}

Element* XPath::getSiblingByTag(Element* root, String& name)
{
    if (!root) {
        return nullptr;
        std::cout << "NULLL" << std::endl;
    }
   
    Element* current = dynamic_cast<Element*>(root);
    while (current) {
        if (current && current->getName() == name) {
            return current;
        }
        current = dynamic_cast<Element*>(current->getNextSibling());
    }
}

void XPath::getTextNodesOfElement(Node* element)
{
    if (!element) {
        std::cout << "null" << std::endl;
    }
    Element* elementNode = dynamic_cast<Element*>(element);
    Text* current = dynamic_cast<Text*>(elementNode->getFirstChild());
    while (current) {
        if (current->getText() != "") {
            std::cout << current->getText() << std::endl;
        }
        current = dynamic_cast<Text*>(current->getNextSibling());
    }
}

void XPath::printTextNodesOf(String& text, Element* root)
{
    if (!root) {
        std::cout << "null root" << std::endl;
    }
    
    String first, second;
    separateString(first, second, text);

    Element* currentSibling = getSiblingByTag(root, first);
    while (currentSibling) {
        Node* current = currentSibling->getFirstChild();
        while (current) {
            if (current->getName() == second) {
                getTextNodesOfElement(current);
            }
            current = dynamic_cast<Element*>(current->getNextSibling());
        }
        Element* next = dynamic_cast<Element*>(currentSibling->getNextSibling());
        currentSibling = getSiblingByTag(next, first);
    }
}

void XPath::printTextNodesOfIndex(String& text, Element* root) {
    String first, second;
    separateString(first, second, text);
    
    int index = getIndex(second);
    Element* currentSibling = getSiblingByTag(root, first);

    while (currentSibling) {
        Node* current = currentSibling->getFirstChild();
        int count = 0; 
        while (current) {
            if (current->getName() == second) {
                if (count == index) {
                    getTextNodesOfElement(current);
                }
                count++;
            }
            current = current->getNextSibling();
        }
        currentSibling = dynamic_cast<Element*>(currentSibling->getNextSibling());
    }
}

void XPath::printIdAttributeOfIndex(String& text, Element* root)
{
    

}

