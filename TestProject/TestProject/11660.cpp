#include <bits/stdc++.h>
using namespace std;
int MAP[1025][1025];
int total[1025][1025];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
			total[i][j] = total[i][j - 1] + MAP[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int j = x1; j <= x2; j++) {
			sum += total[j][y2] - total[j][y1 - 1];
		}

		cout << sum << '\n';
	}
	return 0;
}