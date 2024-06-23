#include "Element.h"

Element::Element(const String& name) : name(name), firstAttribute(nullptr), firstChild(nullptr)
{
    setNextSibling(nullptr);
}

Element::~Element()
{
    delete firstAttribute;
    delete firstChild;
}

void Element::setName(const String& name)
{
    this->name = name;
}

void Element::setFirstAttribute(Attribute* firstAttribute)
{
    this->firstAttribute = firstAttribute;
}

void Element::setFirstChild(Node* firstChild)
{
    this->firstChild = firstChild;
}

String Element::getName() const
{
    return name;
}

Attribute* Element::getFirstAttribute() const
{
    return firstAttribute;
}

Node* Element::getFirstChild() const
{
    return firstChild;
}

void Element::addAttribute(Attribute* attribute)
{
    if (!firstAttribute) {
        firstAttribute = attribute;
    }
    else {
        Attribute* temp = firstAttribute;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
       
        temp->setNext(attribute);
    }
}

void Element::addChild(Node* child)
{
    //std::cout << "in add child "<<firstChild << std::endl;
    if (!firstChild) {
        firstChild = child;
        //std::cout << "first child " << firstChild << std::endl;
    }
    else {
        Node* temp = firstChild;
        //std::cout << "vliza v while " << std::endl;
        while (temp->getNextSibling()) {
            temp = temp->getNextSibling();
            //std::cout << temp << std::endl;
        }
        //std::cout << "setva nextsibl" << std::endl;
        temp->setNextSibling(child);
        //std::cout << "nextsibl "<<temp->getNextSibling() << std::endl;
    }
    //std::cout << std::endl;
}

String Element::toString() const
{
    String result("<");
    result += name;
    Attribute* attr(firstAttribute);
    while (attr) {
        (result += " ") + attr->toString();
        attr = attr->getNext();
    }
    result += ">";
    Node* child = firstChild;
    while (child) {
        result += child->toString();
        child = child->getNextSibling();
    }
    (((result += "</") + name) += ">");
    return result;
}

