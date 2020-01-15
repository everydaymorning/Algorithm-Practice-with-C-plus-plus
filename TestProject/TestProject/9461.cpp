#include <bits/stdc++.h>
using namespace std;
long long dp[101];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;


		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}

		cout << dp[n] << '\n';
	}
	

	return 0;
}