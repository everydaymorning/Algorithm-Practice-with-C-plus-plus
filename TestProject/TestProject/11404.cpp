#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
const int MAX = 1000000000;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = MAX;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dp[a - 1][b - 1] = min(dp[a - 1][b - 1], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == MAX) dp[i][j] = 0;
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}