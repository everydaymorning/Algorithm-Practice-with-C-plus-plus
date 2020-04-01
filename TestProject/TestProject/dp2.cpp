#include <bits/stdc++.h>
using namespace std;
long long dp[81];
int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	long long sum = 0;
	sum = dp[n] * 2 + (dp[n - 1] + dp[n]) * 2;
	cout << sum;
	return 0;
}