#include "bst.h"

// OBST�� �����ϱ� ���� Ŭ����

bst::bst() {
	this->root = NULL;
}

void bst::buildOptimalBST(string* words, int* p, int* q, int n) {
	
	int size = n + 2;

	int** e = new int* [size];
	int** w = new int* [size];
	int** r = new int* [size];
	node** tree = new node*[n + 1]; // ��� �����͵��� ĳ���� ������ �迭

	for (int i = 0; i < size; i++)
	{
		e[i] = new int[size];
		w[i] = new int[size];
		r[i] = new int[size];
	}

	// �ʱ�ȭ
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			e[i][j] = 0;
			w[i][j] = 0;
			r[i][j] = 0;
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
					r[i][j] = p;
				}
			}
		}
	}

	this->putItems(r, tree, words, 1, n);
	this->root = tree[(r[1][n])];

	for (int i = 0; i < size; ++i)
	{
		delete[] e[i];
		delete[] w[i];
		delete[] r[i];
	}
	delete[] e;
	delete[] w;
	delete[] r;
	delete[] tree;

	return;
}

void bst::putItems(int** r, node** tree, string* words, int i, int j) {

	// ���� ����
	int p = r[i][j];

	if (j >= i)
	{
		// 1. ������ Ž������ ��带 ����
		node* data = new node(*(words + p - 1), NULL, NULL);
		tree[p] = data; // tree �迭�� ��带 ĳ��

		// 2. ���� ���� Ʈ�� Ž��
		this->putItems(r, tree, words, i, p - 1);

		// 3. ���� Ʈ���� ��Ʈ ��忡 ���� �ڽ� ��� ����
		if (r[i][p - 1] != 0)
		{
			data->insertLeftChild(tree[r[i][p-1]]);
		}

		// 4. ������ ���� Ʈ�� Ž��
		this->putItems(r, tree, words, p + 1, j);

		// 5. ���� Ʈ���� ��Ʈ ��忡 ������ �ڽ� ��� ����
		if (r[p + 1][j] != 0)
		{
			data->insertRightChild(tree[r[p + 1][j]]);
		}
	}

	return;
}

void bst::printTree(node* node, int tab) 
{
	static int d_num = 0;

	if (node != NULL)
	{
		for (int i = 0; i < tab; i++)
		{
			cout << '\t';
		}
		cout << node->getData() << endl;
		tab++;
		printTree(node->getLeftChild(), tab);
		printTree(node->getRightChild(), tab);
	}
	else 
	{
		for (int i = 0; i < tab; i++)
		{
			cout << '\t';
		}
		cout << "d" << d_num++ << endl;
		tab++;
	}

	return;
}
