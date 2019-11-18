#include <iostream>
#include <utility>
#include <string>
#include <cstdlib>
#include <ctime>
#include <tree/Heap.h>
#include <tree/binaryTreeNode.h>
#include <tree/Huffman.h>

using namespace std;

void dfs(binaryTreeNode<pair<char, int>>* t, string str) {
	if (t->leftChild == nullptr) {
		cout << t->element.first << ' ' << str << endl;
		return;
	} else dfs(t->leftChild, str + '0');

	if (t->rightChild == nullptr) {
		cout << t->element.first << ' ' << str << endl;
		return;
	} else dfs(t->rightChild, str + '1');
}

void heapSort() {
	int n;
	cin >> n;
	srand(time(nullptr));
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 1000;
		cout << a[i] << ' ';
	}
	cout << endl;
	Heap<int> h;
	h.init(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		int x = h.top();
		h.pop();
		a[i] = x;
		h.output(cout, '|');
		for (int j = i; j < n; ++j)	cout << ' ' << a[j];
		cout << endl;
	}
}

void task1() {
	int n, x;
	cin >> n;
	const auto a = new int[n];
	for (int i = 0; i < n; ++i)	cin >> a[i];

	Heap<int, less<>> h;
	h.init(a, a + n);

	h.output(cout);

	cout << "插入的元素: ";
	cin >> x;
	h.push(x);

	h.output(cout);

	cout << "删除的元素: ";
	cin >> x;
	h.erase(x);
	h.output(cout);
}

void task3() {
	int n;
	cout << "字符个数: ";
	cin >> n;
	const auto a = new pair<char, int>[n];
	for (int i = 0; i < n; ++i) {
		char c;
		int w;
		cin >> c >> w;
		a[i] = make_pair(c, w);
	}

	Huffman<char> huff(n, a);
	binaryTreeNode<pair<char, int>>* root = huff.create();

	cout << "层次遍历: ";
	huff.levelOrder(root);
	cout << endl;
	cout << "前序遍历: ";
	huff.preOrder(root);
	cout << endl;

	cout << "编码为:" << endl;
	dfs(root, "");
}


int main() {
	task1();
	heapSort();
	task3();
	return 0;
}
