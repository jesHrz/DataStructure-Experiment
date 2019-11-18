#include <iostream>
#include "test2.h"

using namespace std;

char e[55][55];
bool vis[55][55];

void print(linkedStack<Runtime>& s) {//输出路径
	if (s.size() == 1) {
		Runtime cur = s.top(); s.pop();
		cout << "(" << cur.x << ", " << cur.y << ')';
		return;
	}
	Runtime cur = s.top(); s.pop();
	print(s);
	cout << " -> (" << cur.x << ", " << cur.y << ')';
}

void test2() {
	int n, m, sx, sy, ex, ey;
	int dx[4] = { 0, -1, 0, 1 }, dy[4] = { 1, 0, -1, 0 };

	cout << "请依次输入迷宫的行列、入口坐标、出口坐标、迷宫: " << endl;
	cin >> n >> m >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; ++i)	cin >> e[i] + 1;

	//模拟系统栈进行dfs
	linkedStack<Runtime> s;
	int i;
	vis[sx][sy] = true;
	s.push({ sx, sy, 0 });
	while (!s.empty()) {
		Runtime cur = s.top(); s.pop();
		for (i = cur.i; i < 4; ++i) {
			if (i == 0 && cur.x == ex && cur.y == ey) {
				cout << "路径为: " << endl;
				print(s);
				cout << " -> (" << cur.x << " ," << cur.y << ')' << endl;
				return;
			}
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (tx > 0 && tx <= n && ty > 0 && ty <= m && !vis[tx][ty] && e[tx][ty] == '0') {
				vis[tx][ty] = true;
				cur.i = i + 1;
				s.push(cur);
				s.push({ tx, ty, 0 });
				break;
			}
		}
	}
	cout << "无解" << endl;
}