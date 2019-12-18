#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		int cnt = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			int tmp;
			cin >> tmp;

			q.push(make_pair(j, tmp));
			pq.push(tmp);
		}

		while (!q.empty()) {
			int idx = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (b == idx) {
					printf("%d\n", cnt);
					break;
				}
			}
			else {
				q.push(make_pair(idx, value));
			}
		}

	}

	return 0;
}