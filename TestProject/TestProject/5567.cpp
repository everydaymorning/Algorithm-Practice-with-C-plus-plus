#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> v[501];
bool check[501];
int cnt;
void bfs(int idx) {
	queue<pair<int, int>> q;
	q.push({ idx, 0 });
	check[idx] = true;

	while (!q.empty()) {
		int s = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist >= 1 && dist <= 2) cnt++;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i];
			if (check[next]) continue;
			q.push({ next, dist + 1 });
			check[next] = true;
		}
	}

	cout << cnt;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}


	bfs(1);
	return 0;
}