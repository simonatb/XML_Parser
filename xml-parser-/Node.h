#pragma once
#include "String.h"
class Node {
	Node* nextSibling=nullptr;
public:
	Node() :nextSibling(nullptr) {};
	virtual ~Node() = default ;
	virtual String toString() const = 0;
	virtual String getName() const = 0;
	void setNextSibling(Node* nextSibling);
	Node* getNextSibling() const;
};
