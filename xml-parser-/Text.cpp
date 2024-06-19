#include "Text.h"

Text::Text(const MyString& text) :text(text)
{
    setNextSibling(nullptr);
}

MyString Text::toString() const
{
    return text;
}

void Text::setText(const MyString& text)
{
    this->text = text;
}

MyString Text::getText() const
{
    return text;
}

