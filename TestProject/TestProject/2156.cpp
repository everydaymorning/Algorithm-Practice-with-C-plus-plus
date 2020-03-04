#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10001];
int dp[10001];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]); // n-1ÀÜÀ» ¾È¸Ô¾úÀ» ¶§, n-1ÀÜÀ» ¸Ô¾úÀ» ¶§
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n];
	return 0;

}