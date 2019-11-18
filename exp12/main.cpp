#include <iostream>
#include <graph/adjacencyGrap.h>
#include <graph/linkedGraph.h>

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
	cout << "dfs" << endl;
	cout << g.connectedComponent(true);
	cout << endl;
	cout << "bfs" << endl;
	cout << g.connectedComponent(false);
	cout << endl << "distance between 5 and 2" << g.dis(5, 2) << endl;
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