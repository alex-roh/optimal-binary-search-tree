#include "bst.h"

// OBST를 구현하기 위한 클래스

bst::bst() {
	this->root = NULL;
}

void bst::buildOptimalBST(string* words, int* p, int* q, int n) {
	
	// n = 5

	int size = n + 2;

	int** e = new int* [size];
	int** w = new int* [size];
	int** root = new int* [size];

	for (int i = 0; i < size; i++)
	{
		e[i] = new int[size];
		w[i] = new int[size];
		root[i] = new int[size];
	}

	// 초기화
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			e[i][j] = 0;
			w[i][j] = 0;
			root[i][j] = 0;
		}
	}

	// 표에서 e[1, 0], e[2, 1], e[3, 2]... 부분을 채움
	for (int i = 1; i < size - 1; i++)
	{
		int j = i - 1;
		e[i][j] = q[j];
		w[i][j] = q[j];
	}

	// 대각선이 시작하는 열마다 순회
	for (int diag = 1; diag < size - 1; diag++)
	{
		// 대각선을 타고 계단처럼 행을 내려감
		for (int i = 1; i < size - diag; i++)
		{
			int j = diag + i - 1; // 현재 대각선의 행에서의 열
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];

			// 캐싱되어 있는 값을 이용해 현재 위치의 최적해를 구함
			for (int p = i; p <= j; p++)
			{
				int temp = e[i][p - 1] + e[p + 1][j] + w[i][j];
				if (temp < e[i][j])
				{
					e[i][j] = temp;
					root[i][j] = p;
				}
			}
		}
	}





	for (int i = 0; i < size; ++i) {
		delete[] e[i];
		delete[] w[i];
		delete[] root[i];
	}
	delete[] e;
	delete[] w;
	delete[] root;

	this->putItems(words);
	return;
}

void bst::putItems(string* word) {
	// Insert source code here...












	return;
}

void bst::printTree(void) {
	// Insert source code here...

	return;
}
