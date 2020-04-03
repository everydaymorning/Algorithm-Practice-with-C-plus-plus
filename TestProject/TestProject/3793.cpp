#include <bits/stdc++.h>
using namespace std;
int dp[201][201];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str1, str2;
	while (1) {
		cin >> str1 >> str2;
		if (cin.eof()) break;

		str1 = '0' + str1;
		str2 = '0' + str2;
		int len1 = str1.size();
		int len2 = str2.size();
		//cout << "len1: " << len1 << "  len2: " << len2 << '\n';
		for (int i = 1; i < len2; i++) {
			for (int j = 1; j < len1; j++) {
				if (str2[i] == str1[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}/*
		for (int i = 0; i < len2; i++) {
			for (int j = 0; j < len1; j++) {
				cout << dp[i][j] << " ";
			}
			cout << '\n';
		}*/
		cout << dp[len2 - 1][len1 - 1] << '\n';
		for (int i = 0; i < 201; i++) {
			for (int j = 0; j < 201; j++) {
				dp[i][j] = 0;
			}
		}
	}

	return 0;
}