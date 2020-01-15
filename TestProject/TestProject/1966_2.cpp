#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			q.push(make_pair(i, s));
			pq.push(s);
		}
		int cnt = 1;
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (val != pq.top()) {
				q.push(make_pair(idx, val));
			}
			else {
				if (idx == m) {
					break;
				}
				else {
					pq.pop();
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}