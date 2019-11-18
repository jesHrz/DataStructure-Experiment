#include <iostream>
#include <tree/binarySearchTree.h>

using namespace std;

int main() {
	binary_seach_tree<int> t;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		t.insert(a);
	}
	cout << "ascend: ";
	t.ascend();

	cout << "height: " << t.height() << endl;

	cin >> n;
	auto p = t.find(n);
	cout << endl;
	if (p == nullptr)	cout << "failed" << endl;

	cin >> n;
	p = t.find_by_rank(n);
	cout << endl;
	if (p == nullptr)	cout << "failed" << endl;

	cin >> n;
	t.erase(n);
	cout << "ascend" << endl;
	t.ascend();

	cin >> n;
	t.erase_by_rank(n);
	cout << "ascend" << endl;
	t.ascend();
	return 0;
}
