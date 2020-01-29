#include <bits/stdc++.h>
using namespace std;
int dp[5001];
int arr[5001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	int str_size = str.size();
	for (int i = 1; i <= str_size; i++) {
		arr[i] = str[i - 1] - '0';
	}
	if (str_size == 0 && arr[1] == 0) {
		cout << "0";
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= str_size; i++) {
		if (arr[i] > 0 && arr[i] < 10) {
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;
		}
		if (i == 1) continue;
		int tmp = (arr[i - 1] * 10) + arr[i];
		if (tmp >= 10 && tmp <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
		
	}
	cout << dp[str_size];
	return 0;
}