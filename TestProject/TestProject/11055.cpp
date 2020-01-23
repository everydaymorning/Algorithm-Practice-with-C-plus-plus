#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];

		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		res = max(res, dp[i]);
	}

	cout << res;
	return 0;
}