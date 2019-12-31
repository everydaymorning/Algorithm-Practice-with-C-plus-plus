#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> v1[1001];
bool check1[1001];
void bfs(int start) {
	if (check1[start]) return;
	queue<int> q;
	q.push(start);
	check1[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < v1[x].size(); i++) {
			int y = v1[x][i];
			if (check1[y]) continue;
			check1[y] = true;
			q.push(y);

		}

	}
}

void dfs(int start) {
	if (check1[start]) return;
	check1[start] = true;

	printf("%d ", start);
	for (int i = 0; i < v1[start].size(); i++) {
		int y = v1[start][i];
		dfs(y);
	}

}
int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v1[a].push_back(b);
		v1[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		sort(v1[i].begin(), v1[i].end());
	}
	dfs(v);
	memset(check1, false, sizeof(check1));
	printf("\n");
	bfs(v);
	return 0;
}