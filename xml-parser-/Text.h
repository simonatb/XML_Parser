#pragma once
#include "Node.h"
class Text : public Node
{
	String text;
public:
	Text(const String& text);
	String toString() const override;
    
	void setText(const String& text);
	String getText() const;
	String getName()const {
		String empty("");
		return empty;
	}
};


