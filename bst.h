#pragma once
#include <iostream>
#include "node.h"
using namespace std;

// OBST를 구현하기 위한 클래스
class bst {
private:
	void putItems(int** r, node** tree, string* word, int i, int j);

public:
	node* root;
	bst();
	void buildOptimalBST(string* words, int* p, int* q, int n);
	void printTree(node* node, int tab);
};
