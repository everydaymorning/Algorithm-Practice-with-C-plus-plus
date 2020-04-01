#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;
	v.push_back({ 7 });
	v.push_back({ 3,8 });
	v.push_back({ 8,1,0 });
	v.push_back({ 2,7,4,4 });
	v.push_back({ 4,5,2,6,5 });
	dp[0][0] = v[0][0];
	int MAX = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + v[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		MAX = max(MAX, dp[n - 1][i]);
	}
	cout << MAX;
	return 0;
}