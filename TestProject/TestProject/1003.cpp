#include <bits/stdc++.h>
using namespace std;

int zero = 0;
int one = 0;
int dp[40];
int dp2[40];
int main() {
	int t;
	cin >> t;

	while (t--) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin >> n;
		
		dp[0] = 1;
		dp2[0] = 0;

		dp[1] = 0;
		dp2[1] = 1;
		if (n >= 2) {
			for (int i = 2; i <= n; i++) {
				dp[i] = dp[i - 2] + dp[i - 1];
				dp2[i] = dp2[i - 2] + dp2[i - 1];
			}
		}
		
		cout << dp[n] << " " << dp2[n] << '\n';
	}

	return 0;
}