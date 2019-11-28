#include "bst.h"

// OBST�� �����ϱ� ���� Ŭ����

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

	// �ʱ�ȭ
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			e[i][j] = 0;
			w[i][j] = 0;
			root[i][j] = 0;
		}
	}

	// ǥ���� e[1, 0], e[2, 1], e[3, 2]... �κ��� ä��
	for (int i = 1; i < size - 1; i++)
	{
		int j = i - 1;
		e[i][j] = q[j];
		w[i][j] = q[j];
	}

	// �밢���� �����ϴ� ������ ��ȸ
	for (int diag = 1; diag < size - 1; diag++)
	{
		// �밢���� Ÿ�� ���ó�� ���� ������
		for (int i = 1; i < size - diag; i++)
		{
			int j = diag + i - 1; // ���� �밢���� �࿡���� ��
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];

			// ĳ�̵Ǿ� �ִ� ���� �̿��� ���� ��ġ�� �����ظ� ����
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
