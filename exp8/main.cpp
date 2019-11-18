#include <iostream>
#include <ctime>
#include <hash/hashChain.h>
#include <hash/hashTable.h>

using namespace std;

int main() {
	int rmd[500];
	hashTable<int, int> h(961);
	srand(time(0));
	for (int i = 0; i < 500; ++i) {
		rmd[i] = rand();
		for (int j = 0; j < i; ++j) {
			if (rmd[j] == rmd[i]) {
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 500; ++i) {
		h.insert(rmd[i], i);
	}
	h.output(cout);
	int key;
	while (true) {
		cout << "search:";
		cin >> key;
		if (key == -1)	break;
		auto kv = h.find(key);
		if (kv == nullptr)	cout << "It is NULL" << endl;
		else cout << "The element is: " << kv->first << ' ' << kv->second << endl;
	}

	return 0;
}
