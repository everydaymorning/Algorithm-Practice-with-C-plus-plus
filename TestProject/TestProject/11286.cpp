#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.size() == 0) {
				cout << "0" << '\n';
				continue;
			}
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			pq.push({ abs(x), x });
		}
	}
}