#include <bits/stdc++.h>
using namespace std;
int dp[13];

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = i * dp[i - 1];
	}

	cout << dp[n];
	return 0;
}