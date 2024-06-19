#pragma once
#include "MyString.h"
class Node {
	Node* nextSibling;
public:
	virtual ~Node() = default;
	virtual MyString toString() const = 0;

	void setNextSibling(Node* nextSibling);
	Node* getNextSibling() const;
};
