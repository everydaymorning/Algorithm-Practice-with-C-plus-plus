#include <bits/stdc++.h>
using namespace std;
int dp[40];
bool check[40];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		check[a] = true;
	}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	int res = 1;
	int cnt = 1;

	for (int i = 1; i <= n; i++) {
		if (check[i]) {
			res *= dp[cnt - 1];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	res *= dp[cnt-1];

	cout << res;



	return 0;
}
