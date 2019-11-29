#pragma once
#include <string>
#include <cstdlib>
using namespace std;

class node {
private:
	string data;
	node* left_child;
	node* right_child;

public:
	node(string data, node* left, node* right);
	void insertData(string data);
	void insertLeftChild(node* left);
	void insertRightChild(node* right);
};