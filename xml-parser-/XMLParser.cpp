#include "XMLParser.h"

// Helper functions
void skipWhitespace(String& xml, size_t& pos) {
    while (pos < xml.length() && xml.isSpace(pos)) {
        ++pos;
    }
}

unsigned charSize(const char* first) {
    if (first == nullptr) {
        return 0;
    }

    int length = 0;
    while (*first != '\0') {
        first++;
        length++;
    }
    return length;
}


bool startsWith(const char* text, const char* pattern) {
    if (!text || !pattern) {
        return false;
    }

    while (*text != '\0' && *pattern != '\0') {
        if (*text != *pattern) {
            return false;
        }
        text++;
        pattern++;
    }
    return *pattern == '\0';
}

bool isSubstring(const char* text, const char* pattern) {
    if (!text || !pattern) {
        return false;
    }

    unsigned textLength = charSize(text);
    unsigned patternLength = charSize(pattern);

    while (textLength >= patternLength) {
        if (startsWith(text, pattern)) {
            return true;
        }
        text++;
        textLength--;
    }
    return false;
}

XMLParser::XMLParser(const String& filename) : filename(filename) {}

Element* XMLParser::parseXML() {
    String buffer;
    buffer.readFile(filename.c_str());

    Element* root = nullptr;
    Element* current = nullptr;
    size_t pos = 0;
    while (pos < buffer.length()) {
        skipWhitespace(buffer, pos);

        if (buffer[pos] == '<' && buffer[pos + 1] != '/') {
            Element* element = parseElement(buffer, pos);
            if (element) {
                if (!root) {
                    root = element;                   
                }
                else if (!current) {
                    current = element;
                    root->setNextSibling(current);
                }
                else {

                    current->setNextSibling(element); 
                    current = element;

                }
            }
        }
        else {
            ++pos;
        }
    }
    return root;
}

Element* XMLParser::parseElement(String& buffer, size_t& pos) {
    skipWhitespace(buffer, pos);
    ++pos;

    String name = parseName(buffer, pos);
    Element* element = new Element(name);

    parseAttributes(element, buffer, pos);

    if (buffer[pos] == '/' && buffer[pos + 1] == '>') {
        pos += 2;
        return element;
    }

    ++pos; 

    while (pos < buffer.length() && !(buffer[pos] == '<' && buffer[pos + 1] == '/')) {
        if (buffer[pos] == '<') {
            Element* child = parseElement(buffer, pos);
            if (child) {
                element->addChild(child);
            }
        }
        else {
            Text* text = parseText(buffer, pos);
            if (text) {
                element->addChild(text);
            }
        }
        skipWhitespace(buffer, pos);
    }

    pos += 2 + name.length() + 1;

    return element;
}

void XMLParser::parseAttributes(Element* element, String& buffer, size_t& pos) {
    skipWhitespace(buffer, pos);
    while (buffer[pos] != '>' && buffer[pos] != '/') {
        String name = parseName(buffer, pos);
        skipWhitespace(buffer, pos);
        ++pos; 
        skipWhitespace(buffer, pos);
        char quote = buffer[pos++];
        size_t start = pos;
        while (buffer[pos] != quote) {
            ++pos;
        }

        String value = buffer.substr(start, pos - start);
        ++pos;
        Attribute* attribute = new Attribute(name, value);
        element->addAttribute(attribute);
        skipWhitespace(buffer, pos);
    }
}

Text* XMLParser::parseText(String& buffer, size_t& pos) {
    size_t start = pos;
    while (pos < buffer.length() && buffer[pos] != '<') {
        if (buffer[pos] == '\n') {
            return nullptr;
        }
        ++pos;
    }
    String text = buffer.substr(start, pos - start);
    
    if (text != "\n") {
        return new Text(text);
    }
    
}

String XMLParser::parseName(String& buffer, size_t& pos) {
    size_t start = pos;
    while (pos < buffer.length() && (buffer.isAlnum(pos))) {
        ++pos;
    }
    return buffer.substr(start, pos - start);
}

void XMLParser::print(Element* element) {
    
    while (element) {
        std::cout << "Element: " << element->getName() << std::endl;

        Attribute* attr = element->getFirstAttribute();
        while (attr) {
            std::cout << "  Attribute: " << attr->getName() << " = " << attr->getValue() << std::endl;
            attr = attr->getNext();
        }

        Node* child = element->getFirstChild();
        while (child) {
            Element* childElement = dynamic_cast<Element*>(child);
            if (childElement) {
                print(childElement);
                break;
            }
            else {
                Text* textNode = dynamic_cast<Text*>(child);
                if (textNode) {
                    std::cout << "  Text: " << textNode->getText() << std::endl;
                }
            }
            if (child->getNextSibling()) {           
                child = child->getNextSibling();
            }
            else {
                child = nullptr;
            }
        }
        if (element->getNextSibling()) {
            element = dynamic_cast<Element*>(element->getNextSibling());
        }
        else
        {
            element=nullptr;
        }
    }
    std::cout << std::endl;
}
