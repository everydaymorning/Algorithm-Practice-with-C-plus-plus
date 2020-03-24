#include <bits/stdc++.h>
using namespace std;

int MAP[1001][1001];
int candy[1001][1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			candy[i][j] = max(max(candy[i - 1][j - 1], candy[i - 1][j]), candy[i][j - 1]) + MAP[i][j];
		}
	}

	cout << candy[n][m];
	return 0;
}