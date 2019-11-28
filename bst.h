#pragma once
#include <iostream>
#include "node.h"
using namespace std;

// OBST를 구현하기 위한 클래스
class bst {
private:
	node* root;
	void putItems(string* words);

public:
	bst();
	void buildOptimalBST(string* words, int* p, int* q, int n);
	void printTree(void);
};
