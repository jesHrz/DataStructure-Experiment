#include <iostream>
#include <linearList/chain.h>
using namespace std;

template<typename T>
void show(const chain<T>& c) {
	for (auto it = c.begin(); it != c.end(); ++it)	cout << *it << ' ';
	cout << endl;
}

template<typename T>
chain<T> merge(const chain<T>& a, const chain<T>& b) {
	chain<T> c;
	typename chain<T>::const_iterator it1 = a.begin();
	typename chain<T>::const_iterator it2 = b.begin();
	while (it1 != a.end() && it2 != b.end()) {
		if (*it1 <= *it2)	c.push_back(*(it1++));
		else	c.push_back(*(it2++));
	}
	while (it1 != a.end())	c.push_back(*(it1++));
	while (it2 != b.end())	c.push_back(*(it2++));
	return c;
}


int main() {
	int n;
	chain<int> c;
	chain<int> a;
	chain<int> b;
	cout << "input the length of chain: ";
	cin >> n;
	cout << "input n numbers: " << endl;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		c.push_back(x);
	}
	cout << "the number in chain are: " << endl;
	for (int i = 0; i < c.size(); ++i)	cout << c[i] << ' ';
	cout << endl;

	cout << "input a number which you want to find:" << endl;
	int x;
	cin >> x;
	cout << c.find(x) << endl;

	cout << "the elements in the chain:" << endl;
	show(c);

	cout << "merge: (note that a is equal to c and so is b)" << endl;
	a = c;
	b = c;
	c = merge(a, b);

	cout << "after merge: " << endl;
	for (auto it = c.begin(); it != c.end(); ++it)	cout << *it << ' ';
	cout << endl;

	return 0;
}
