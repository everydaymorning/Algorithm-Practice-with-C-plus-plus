#include <bits/stdc++.h>
using namespace std;
// ��ŸƮ��ũ BOJ 5014 BFS����
int dis[1000001];
int f, s, g, u, d;
int bfs() {
	queue<int> q;
	q.push(s);
	dis[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		if (x == g) {
			return dis[x] - 1;
		}
		int next[2] = { x + u, x - d };
		for (int i = 0; i < 2; i++) {
			if (next[i] <= f && next[i] > 0 && dis[next[i]] == 0) { // ���� ���� �ְ� �湮���� ���� ���̸� ť�� �ְ� �Ÿ� 1 ����
				q.push(next[i]);
				dis[next[i]] = dis[x] + 1;
			}
		}
		
	}
	return -1; // ã�� ���ϸ� -1 ����
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> f >> s >> g >> u >> d;
	int res = bfs();

	if (res == -1) {
		cout << "use the stairs";
	}
	else {
		cout << res;
	}
	return 0;
}