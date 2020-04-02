#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int dp[101][101][101];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;
		str = '0' + str;
		v.push_back(str);
	}
	int MIN = 101;
	
	int len1 = v[0].size();
	int len2 = v[1].size();
	int len3 = v[2].size();
	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			for (int k = 1; k < len3; k++) {
				if (v[0][i] == v[1][j] && v[1][j] == v[2][k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					int tmp = 0;
					tmp = max(tmp, dp[i - 1][j][k]);
					tmp = max(tmp, dp[i][j - 1][k]);
					tmp = max(tmp, dp[i][j][k - 1]);
					dp[i][j][k] = tmp;
				}
			}
		}
	}

	cout << dp[len1 - 1][len2 - 1][len3 - 1];
	
	return 0;
}