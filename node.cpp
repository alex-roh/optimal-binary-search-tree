#include "node.h"

// »ý¼ºÀÚ
node::node() {
	this->data = "";
	this->left_child = NULL;
	this->right_child = NULL;
}

node::node(string data, node* left, node* right)
{
	this->data = data;
	this->left_child = left;
	this->right_child = right;
}

void node::insertLeftChild(node* left)
{

}

void node::insertRightChild(node* right)
{


}