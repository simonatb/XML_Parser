#pragma once
#include "Node.h"
class Text : public Node
{
public:
	String text;
public:
	Text(const String& text);
	String toString() const override;

	void setText(const String& text);
	String getText() const;
};


