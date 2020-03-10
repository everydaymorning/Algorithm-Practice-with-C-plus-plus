#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			q.push({ i,t });
			pq.push(t);
		}
		
		int cnt = 1;
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (val != pq.top()) {
				q.push({ idx, val });
			}
			else {
				if (idx == m) break;
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