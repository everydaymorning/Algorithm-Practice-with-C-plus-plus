#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[101];
vector<pair<int, int>> num;
bool check[101];
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
void bfs(int idx) {
	queue<pair<int, int>> q;
	q.push({ idx,0 });
	check[idx] = true;
	int mx = 0;
	while (!q.empty()) {
		int s = q.front().first;
		int dist = q.front().second;
		q.pop();
		mx += dist;
		for (int i = 0; i < v[s].size(); i++) {
			int next = v[s][i];
			if (check[next]) continue;
			q.push({ next, dist + 1 });
			check[next] = true;
		}
	}
	num.push_back({ idx, mx });
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
	sort(num.begin(), num.end(), cmp);
	cout << num[0].first;
	return 0;
}