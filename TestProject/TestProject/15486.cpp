#include <bits/stdc++.h>
using namespace std;
int arr[1500001][2];
int dp[1500001];
int n;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int cur = 0;
	for (int i = 1; i <= n+1; i++) {
		cur = max(cur, dp[i]);
		//cout << "cur: " << cur << "  dp: " << dp[i] << "  i: " << i << '\n';
		if (i + arr[i][0] > n + 1) continue;

		dp[i + arr[i][0]] = max(cur + arr[i][1], dp[i + arr[i][0]]);

	}
	cout << cur;
	return 0;
}