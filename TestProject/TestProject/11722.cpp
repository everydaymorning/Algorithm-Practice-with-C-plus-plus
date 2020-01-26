#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int arr[1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;

		for (int j = 1; j <= i; j++) {
			if (arr[i] < arr[j] && dp[j] + 1 > dp[i]) { // 1 6 5 7 2 4
				dp[i] = dp[j] + 1;
			}
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}