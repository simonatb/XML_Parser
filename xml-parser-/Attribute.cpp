#include "Attribute.h"

Attribute::Attribute(const MyString& name, const MyString& value) :name(name), value(value), next(nullptr) {}

Attribute::~Attribute()
{
    name = value = "";
    delete next;
}

MyString Attribute::toString() const
{
    MyString result;
    return ((((result += name) += "=\"") += value) += "\"");
}

void Attribute::setName(const MyString& name)
{
    this->name = name;
}

void Attribute::setValue(const MyString& value)
{
    this->value = value;
}

void Attribute::setNext(Attribute* next)
{
    this->next = next;
}

MyString Attribute::getName() const
{
    return name;
}

MyString Attribute::getValue() const
{
    return value;
}

Attribute* Attribute::getNext() const
{
    return next;
}

