#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v1[1001];
bool check[1001];
int cnt;
void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
}

void bfs(int start) {
	queue<int> q;
	for (int j = 1; j <= n; j++) {
		if (check[j]) continue;
		q.push(j);
		check[j] = true;
		cnt++;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < v1[x].size(); i++) {
				int y = v1[x][i];
				if (check[y]) continue;
				check[y] = true;
				q.push(y);
			}
		}
	}

	printf("%d", cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Input();
	bfs(1);
	int a = 123;
	return 0;
}