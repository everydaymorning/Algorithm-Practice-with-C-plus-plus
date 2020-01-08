#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;

	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int c1, c2, r;
			cin >> c1 >> c2 >> r;

			double dis1 = sqrt(pow((x1 - c1), 2) + pow((y1 - c2), 2));
			double dis2 = sqrt(pow((x2 - c1), 2) + pow((y2 - c2), 2));

			if (dis1 <= r && dis2 <= r) continue;
			else if (dis1 <= r || dis2 <= r) cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}