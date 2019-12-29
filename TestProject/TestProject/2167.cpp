#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int dp[301][301];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
			
		}
		
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		printf("%d\n", dp[x][y] - dp[a - 1][y] - dp[x][b - 1] + dp[a - 1][b - 1]);
	}

	return 0;
}