#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int main() {
	int number[3] = { 1,2,3 };

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int j = 4; j <= n; j++) {
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}
		
		printf("%d\n", dp[n]);
	}

	return 0;
}