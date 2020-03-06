#include <bits/stdc++.h>
using namespace std;
int arr[2][100001];
int dp[2][100001];
int t, n;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {

		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + arr[1][j];
		}

		int res = max(dp[0][n], dp[1][n]);
		cout << res << '\n';
	}
	return 0;
}