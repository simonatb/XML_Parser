#include "Attribute.h"

Attribute::Attribute(const String& name, const String& value) :name(name), value(value), next(nullptr) {}

Attribute::~Attribute()
{
    name = value = "";
    delete next;
}

String Attribute::toString() const
{
    String result;
    return ((((result += name) += "=\"") += value) += "\"");
}

void Attribute::setName(const String& name)
{
    this->name = name;
}

void Attribute::setValue(const String& value)
{
    this->value = value;
}

void Attribute::setNext(Attribute* next)
{
    this->next = next;
}

String Attribute::getName() const
{
    return name;
}

String Attribute::getValue() const
{
    return value;
}

Attribute* Attribute::getNext() const
{
    return next;
}

