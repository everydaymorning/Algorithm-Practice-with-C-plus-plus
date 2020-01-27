#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int n;
long long dp[101][101];
//void bfs(int a, int b) {
//	int len = arr[a][b];
//	queue<pair<int, int>> q;
//	q.push(make_pair(a, b + len));
//	q.push(make_pair(a + len, b));
//	check[a][b] = true;
//	while (!q.empty()) {
//		auto cur = q.front();
//		q.pop();
//		int nx = cur.first;
//		int ny = cur.second;
//		if (arr[nx][ny] == 0) {
//			cnt++;
//			continue;
//		}
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//		int tmp = arr[nx][ny];
//		if (nx >= 0 && ny + tmp < n) {
//			q.push(make_pair(nx, ny + tmp));
//		}
//		
//		if (ny >= 0 && nx + tmp < n) {
//			q.push(make_pair(nx + tmp, ny));
//		}
//		
//		
//	}
//}


void func() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

			int val = arr[i][j];
			int down = i + val;
			int right = j + val;

			if (down < n) dp[down][j] += dp[i][j];
			if (right < n) dp[i][right] += dp[i][j];

		}
	}

	cout << dp[n - 1][n - 1];
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	func();

	return 0;

}