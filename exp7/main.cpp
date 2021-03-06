#include <iostream>
#include <queue/linkedQueue.h>

using namespace std;

int main() {
	int n;
	linkedQueue<int>q;

	cin >> n;
	for (int i = 1; i <= n; ++i)	q.push(i);

	while (q.size() > 1) {
		cout << "throw: " << q.front() << endl;
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << "remain: " << q.front() << endl;
	return 0;
}

