#include "bst.h"

// OBST를 구현하기 위한 클래스

bst::bst() {
	this->root = NULL;
}

void bst::buildOptimalBST(string* words, int* p, int* q, int n) {
	
	int size = n + 2;

	int** e = new int* [size];
	int** w = new int* [size];
	int** r = new int* [size];
	node** tree = new node*[n + 1]; // 노드 포인터들을 캐싱할 포인터 배열

	for (int i = 0; i < size; i++)
	{
		e[i] = new int[size];
		w[i] = new int[size];
		r[i] = new int[size];
	}

	// 초기화
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			e[i][j] = 0;
			w[i][j] = 0;
			r[i][j] = 0;
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

	// 변수 선언
	int p = r[i][j];

	if (j >= i)
	{
		// 1. 전순위 탐방으로 노드를 생성
		node* data = new node(*(words + p - 1), NULL, NULL);
		tree[p] = data; // tree 배열에 노드를 캐싱

		// 2. 왼쪽 서브 트리 탐방
		this->putItems(r, tree, words, i, p - 1);

		// 3. 서브 트리의 루트 노드에 왼쪽 자식 노드 삽입
		if (r[i][p - 1] != 0)
		{
			data->insertLeftChild(tree[r[i][p-1]]);
		}

		// 4. 오른쪽 서브 트리 탐방
		this->putItems(r, tree, words, p + 1, j);

		// 5. 서브 트리의 루트 노드에 오른쪽 자식 노드 삽입
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
