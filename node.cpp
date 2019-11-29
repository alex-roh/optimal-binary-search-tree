#include "node.h"

// »ý¼ºÀÚ

node::node(string data, node* left, node* right)
{
	this->data = data;
	this->left_child = left;
	this->right_child = right;
}

void node::insertData(string data)
{
	this->data = data;
}

void node::insertLeftChild(node* left)
{
	this->left_child = left;
}

void node::insertRightChild(node* right)
{
	this->right_child = right;
}