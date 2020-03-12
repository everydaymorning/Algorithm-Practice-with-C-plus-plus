#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[101];
vector<pair<int, int>> v1;
bool check[101];

void bfs(int idx) {
	int sum = 0;
	queue<pair<int, int>> q;
	q.push({ idx, 1 });
	check[idx] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (check[next]) continue;
			q.push({ next, dist + 1 });
			sum += dist;
			check[next] = true;
		}
	}

	v1.push_back({ sum, idx });
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(check, false, sizeof(check));
	}

	sort(v1.begin(), v1.end());
	cout << v1[0].second;
	return 0;
}