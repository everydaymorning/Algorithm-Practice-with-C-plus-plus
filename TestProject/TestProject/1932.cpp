#include <bits/stdc++.h>
using namespace std;
int tri[501][501];
int dp[501][501];
int main() {
	int n;
	cin >> n;


	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];

			if (i == 0) {
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			}
			else if (i == j) {
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tri[i][j];
			}

			if (sum < dp[i][j]) sum = dp[i][j];
		}
	}
	
	printf("%d", sum);
	return 0;
}