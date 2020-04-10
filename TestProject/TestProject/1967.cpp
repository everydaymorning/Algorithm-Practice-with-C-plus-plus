#include <bits/stdc++.h>
using namespace std;
const int MAX = 10001;
vector<pair<int, int>> v[MAX];
bool check[10001];
int sum[10001];
int m_node;
int ans;
void bfs(int pos) {
	queue<int> q;
	q.push(pos);

	while (!q.empty()) {
		int here = q.front();
		check[here] = true;
		q.pop();
		cout << "here: " << here << '\n';
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			cout << "next: " << next << '\n';
			if (check[next]) continue;
			q.push(next);
			sum[next] = v[here][i].second + sum[here];
			cout << "dis: " << v[here][i].second << "  sum[here]: " << sum[here] << "  sum[next]: " << sum[next] << '\n';
			if (sum[next] > ans) {
				ans = sum[next];
				m_node = next;
				cout << "ans: " << ans << '\n';
				cout << "m_node: " << m_node << '\n';
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		v[from].push_back({ to,val });
		v[to].push_back({ from, val });
	}

	bfs(1);
	fill(check, check + MAX, false);
	fill(sum, sum + MAX, 0);
	ans = 0;

	bfs(m_node);

	cout << ans;
	return 0;
}