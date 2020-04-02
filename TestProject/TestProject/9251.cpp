#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str1, str2;
	cin >> str1 >> str2;
	str1 = '0' + str1;
	str2 = '0' + str2;
	for (int i = 1; i < str2.size(); i++) {
		for (int j = 1; j < str1.size() + 1; j++) {
			if (str2[i] == str1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[str2.size() - 1][str1.size() - 1];
	return 0;
}