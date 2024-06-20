#include "Text.h"

Text::Text(const String& text) :text(text)
{
    setNextSibling(nullptr);
}

String Text::toString() const
{
    return text;
}

void Text::setText(const String& text)
{
    this->text = text;
}

String Text::getText() const
{
    return text;
}

