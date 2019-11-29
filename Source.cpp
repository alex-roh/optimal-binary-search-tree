#include <iostream>
#include "bst.h"
using namespace std;

int main(void) {

	bst* tree = new bst();
	string* words = new string[5];
	int* p = new int[6];
	int* q = new int[6];

							p[0] = 0;		q[0] = 500;
	words[0] = "cat";		p[1] = 1500;	q[1] = 1000;
	words[1] = "dog";		p[2] = 1000;	q[2] = 500;
	words[2] = "frog";		p[3] = 500;		q[3] = 500;
	words[3] = "monkey";	p[4] = 1000;	q[4] = 500;
	words[4] = "shark";		p[5] = 2000;	q[5] = 1000;

	// buildOptimalBST 안에서 printTree 함수를 호출합니다.
	tree->buildOptimalBST(words, p, q, 5);
	tree->printTree(tree->root, 0);

	delete p, q, words;
	delete tree;
	return 0;

}