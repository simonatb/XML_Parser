#include "Node.h"

void Node::setNextSibling(Node* nextSibling)
{
	this->nextSibling = nextSibling;
}

Node* Node::getNextSibling() const
{
	return nextSibling;
}