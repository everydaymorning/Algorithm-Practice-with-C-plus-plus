#include <bits/stdc++.h>
using namespace std;
int MAP[501][501];
int n, m;
bool check[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int MAX, total;

void dfs(int x, int y, int cnt) {
	if (cnt == 4) {
		MAX = max(MAX, total);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (check[nx][ny]) continue;
		check[nx][ny] = true;
		total += MAP[nx][ny];
		dfs(nx, ny, cnt + 1);
		total -= MAP[nx][ny];
		check[nx][ny] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(check, false, sizeof(check));
			dfs(i, j, 0);
			if (i + 2 < n && j + 1 < m) { // た
				int sum = MAP[i][j] + MAP[i + 1][j] + MAP[i + 2][j] + MAP[i + 1][j + 1];
				if (sum > MAX) MAX = sum;
			}
			if (i + 1 < n && j + 2 < m) { // ぬ
				int sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i + 1][j + 1];
				if (sum > MAX) MAX = sum;
			}
			if (i - 1 >= 0 && j + 2 < m) { // で
				int sum = MAP[i][j] + MAP[i][j + 1] + MAP[i][j + 2] + MAP[i - 1][j + 1];
				if (sum > MAX) MAX = sum;
			}
			if (i + 2 < n && j - 1 >= 0) { // っ
				int sum = MAP[i][j] + MAP[i + 1][j] + MAP[i + 2][j] + MAP[i + 1][j - 1];
				if (sum > MAX) MAX = sum;
			}
		}
	}
	cout << MAX;
	return 0;
}