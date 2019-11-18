#include <iostream>
#include <tree/linkedBinaryTree.h>
#include <tree/binaryTreeNode.h>

using namespace std;

template<typename T>
void build(const T preOrder[], const T inOrder[], int n, binaryTreeNode<T>*& t) {
	if (n < 1) {
		t = nullptr;
		return;
	}

	int i;
	for (i = 0; i < n && inOrder[i] != *preOrder; ++i);//当前的根节点是*preOrder,在中序遍历中找到*preOrder的位置i

	delete t;
	t = new binaryTreeNode<T>(*preOrder);//建立根节点

	//inOrder[i]的左边是*preOrder的左子树，递归建立左子树
	build(preOrder + 1, inOrder, i, t->leftChild);
	//inOrder[i]的右边是*preOrder的右子树，递归建立右子树
	build(preOrder + i + 1, inOrder + i + 1, n - i - 1, t->rightChild);

	if (t->leftChild != nullptr)	t->leftChild->father = t;
	if (t->rightChild != nullptr)	t->rightChild->father = t;

	//这里可以输出后序遍历
	//cout << *preOrder << ' ';
}

int main() {
	char pre[] = "abdgheckfij";
	char in[] = "gdhbeakcijf";

	linkedBinaryTree<char> t;
	build(pre, in, 11, t.getRoot());

	cout << "树的结点个数: " << t.size() << endl;
	cout << "树的高度: " << t.height() << endl;

	cout << "前序遍历: ";
	t.preOrder();
	cout << endl;

	cout << "中序遍历: ";
	t.inOrder();
	cout << endl;

	cout << "后序遍历: ";
	t.postOrder();
	cout << endl;

	cout << "层次遍历: ";
	t.levelOrder();
	cout << endl;

	return 0;
}
