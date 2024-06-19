#pragma once
#include "Node.h"
class Text : public Node
{
	MyString text;
public:
	Text(const MyString& text);
	MyString toString() const override;

	void setText(const MyString& text);
	MyString getText() const;
};


