#pragma once
#include <string>
#include <cstdlib>
using namespace std;

class node {
public:
	string data;
	node* left_child;
	node* right_child;
	node();
	node(string data, node* left, node* right);
	void insertLeftChild(node* left);
	void insertRightChild(node* right);
};