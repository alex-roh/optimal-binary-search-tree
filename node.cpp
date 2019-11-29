#include "node.h"

// »ý¼ºÀÚ

node::node(string data, node* left, node* right)
{
	this->data = data;
	this->left_child = left;
	this->right_child = right;
}

string node::getData()
{
	return this->data;
}

node* node::getLeftChild()
{
	return this->left_child;
}

node* node::getRightChild()
{
	return this->right_child;
}

void node::insertLeftChild(node* left)
{
	this->left_child = left;
}

void node::insertRightChild(node* right)
{
	this->right_child = right;
}