#include <iostream>
#include <graph/adjacencyGrap.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	adjacencyGraph<int> g(n);
	for (auto i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g.add(u, v, w);
		g.add(v, u, w);
	}
	cout << "Kruskal" << endl;
	cout << g.kru() << endl;
	cout << "Prim" << endl;
	cout << g.prim(1) << endl;
	return 0;
}
/*
5 6
1 3 3
2 3 1
4 1 5
4 5 2
5 1 2
5 2 1
 */
