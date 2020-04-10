#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
vector<pair<int, int>> v[MAX];
bool check[MAX];
int sum[MAX];
int m_node;
int M;
void bfs(int pos) {
	queue<int> q;
	q.push(pos);

	while (!q.empty()) {
		int here = q.front();
		check[here] = true;
		q.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			if (check[next]) continue;
			q.push(next);
			sum[next] = v[here][i].second + sum[here];
			if (sum[next] > M) {
				M = sum[next];
				m_node = next;
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int start, vtx, dis;
		cin >> start;

		while (1) {
			cin >> vtx;
			if (vtx == -1) break;
			cin >> dis;

			v[start].push_back({ vtx, dis });

		}
	}

	bfs(1);
	fill(check, check + MAX, false);
	fill(sum, sum + MAX, 0);
	M = 0;
	bfs(m_node);

	cout << M;
	return 0;
}