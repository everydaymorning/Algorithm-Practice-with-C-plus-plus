#include <bits/stdc++.h>
using namespace std;

int dp[17];
int t[17];
int p[17];
int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		
	}

	for (int i = 1; i <= n; i++) {
		
		if (i + t[i] <= n + 1) { // i번째 날에 일을 했을 때
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			printf("dp[%d + %d] = %d\n", i, t[i], max(dp[i + t[i]], dp[i] + p[i]));
			sum = max(sum, dp[i + t[i]]);
		}

		dp[i + 1] = max(dp[i + 1], dp[i]);
		printf("dp[%d + 1] = %d\n", i, max(dp[i + 1], dp[i]));
		sum = max(sum, dp[i + 1]);

	}
	printf("%d", sum);

	return 0;
}