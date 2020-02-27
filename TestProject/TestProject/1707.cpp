#include <bits/stdc++.h>
using namespace std;
int k, v, e;
vector<int> V[20001];
int check[20001];

void bfs(int idx) {
	queue<int> q;
	int color = 1;
	q.push(idx);
	check[idx] = color;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (check[now] == 1) {
			color = 2;
		}
		else if (check[now] == 2) {
			color = 1;
		}

		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i];
			if (check[next] > 0) continue;
			q.push(next);
			check[next] = color;
		}
	}
}

bool isBipartite() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			int next = V[i][j];
			if (check[i] == check[next]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> k;
	while (k--) {
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			V[a].push_back(b);
			V[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (check[i]) continue;
			bfs(i);
		}

		if (isBipartite()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		for (int i = 1; i <= v; i++) {
			V[i].clear();
		}
		memset(check, false, sizeof(check));
	}
	return 0;
}