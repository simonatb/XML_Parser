#include "XMLEdit.h"

//Helper functions
char fromDigitToChar(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    return '\0';
}

int numberLength(int number) {
    if (number == 0) return 1;  
    int length = 0;
    while (number) {
        number /= 10;
        length++;
    }
    return length;
}

String fromIntToString(int number) {
    if (number == 0) return "0";

    String result;

    int length = numberLength(number);
    for (int i = 0; i < length; i++) {
        int divisor = 1;
        for (int j = 0; j < length - i - 1; j++) {
            divisor *= 10;
        }

        int digit = number / divisor;
        result += fromDigitToChar(digit);
        number %= divisor;
    }

    return result;
}

Element* getSiblingById(Element* root, int id)
{
    String id1 = fromIntToString(id);
    String idString("id");
    if (!root) {
        return nullptr;
        std::cout << "NULLL" << std::endl;
    }

    Element* current = dynamic_cast<Element*>(root);
    while (current) {
        if (current && current->getFirstAttribute()->getName()==idString && current->getFirstAttribute()->getValue()==id1) {
            return current;
        }
        current = dynamic_cast<Element*>(current->getNextSibling());
    }
    return nullptr;
}

void XMLEdit::select(Element* root, int id, const String& key)
{
    if (!root) {
        return;
        std::cout << "NULLL" << std::endl;
    }

    Element* current = getSiblingById(root, id);
   
    if(current) {
        Element* currentChild = dynamic_cast<Element*>(current->getFirstChild());
        while (currentChild) {
            if (currentChild->getFirstAttribute())
            { 
                if (currentChild->getFirstAttribute()->getName() == key) {
                    std::cout << currentChild->getFirstAttribute()->getName() << " = " 
                        << currentChild->getFirstAttribute()->getValue() << std::endl;
                }
            }
            currentChild = dynamic_cast<Element*>(currentChild->getNextSibling());
        }
    }
}

void XMLEdit::set(Element* root, int id, const String& key, const String& value)
{
    if (!root) {
        return;
        std::cout << "NULLL" << std::endl;
    }

    Element* current = getSiblingById(root, id);

    if (current) {
        Element* currentChild = dynamic_cast<Element*>(current->getFirstChild());
        while (currentChild) {
            if (currentChild->getFirstAttribute())
            {
                if (currentChild->getFirstAttribute()->getName() == key) {
                    currentChild->getFirstAttribute()->setValue(value);
                }
            }
            currentChild = dynamic_cast<Element*>(currentChild->getNextSibling());
        }
    }
}

void XMLEdit::children(Element* root, int id)
{
    Element* current = getSiblingById(root, id);

    if (current) {
        Element* currentChild = dynamic_cast<Element*>(current->getFirstChild());
        while (currentChild) {
            if (currentChild->getFirstAttribute())
            {
                std::cout << currentChild->getFirstAttribute()->getName() << " = " << currentChild->getFirstAttribute()->getValue() << std::endl;
            }
            currentChild = dynamic_cast<Element*>(currentChild->getNextSibling());
        }
    }
}

void XMLEdit::childrenNth(Element* root, int id, int n)
{
    Element* current = getSiblingById(root, id);
    int count = 0;
    if (current) {
        Element* currentChild = dynamic_cast<Element*>(current->getFirstChild());
        while (currentChild) {

            if (currentChild->getFirstAttribute())
            {
                if (count <= n) {
                    std::cout << currentChild->getFirstAttribute()->getName() << " = " 
                    << currentChild->getFirstAttribute()->getValue() << std::endl;
                    count++;
                }
            }
            currentChild = dynamic_cast<Element*>(currentChild->getNextSibling());
        }
    }
}

void XMLEdit::deleteAttribute(Element* root, int id, const String& key)
{
    Element* current = getSiblingById(root, id);

    if (current) {
        Element* currentChild = dynamic_cast<Element*>(current->getFirstChild());
        while (currentChild) {
            if (currentChild->getFirstAttribute())
            {
                if (currentChild->getFirstAttribute()->getName() == key) {

                    currentChild->getFirstAttribute()->~Attribute();
                    currentChild->setFirstAttribute(nullptr);
                    return;
                }
            }
            currentChild = dynamic_cast<Element*>(currentChild->getNextSibling());
        }
    }
}

void XMLEdit::addNewChild(Element* root, int id)
{
    Element* current = getSiblingById(root, id);
    if (current) {
        Element* element = new Element("");
        current->addChild(element);
    }
}
