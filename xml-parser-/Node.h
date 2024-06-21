#pragma once
#include "String.h"
class Node {
	Node* nextSibling=nullptr;
public:
	virtual ~Node() = default;
	virtual String toString() const = 0;
	
	void setNextSibling(Node* nextSibling);
	Node* getNextSibling() const;
};
