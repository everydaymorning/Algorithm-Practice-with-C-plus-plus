#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[501][501];
bool check[501][501];
int mx;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		mx = max(mx, sum);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (check[nx][ny]) continue;
		check[nx][ny] = true;
		sum += MAP[nx][ny];
		dfs(nx, ny, cnt + 1, sum);
		sum -= MAP[nx][ny];
		check[nx][ny] = false;
	}
	

}

void type1(int x, int y) { // ㅏ 모양
	int tmp_sum = 0;
	tmp_sum = MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y + 1];
	if (tmp_sum > mx) mx = tmp_sum;
}


void type2(int x, int y) { // ㅓ 모양
	int tmp_sum = 0;
	tmp_sum = MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y - 1];
	if (tmp_sum > mx) mx = tmp_sum;
}


void type3(int x, int y) { // ㅜ 모양
	int tmp_sum = 0;
	tmp_sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x + 1][y + 1];
	if (tmp_sum > mx) mx = tmp_sum;
}

void type4(int x, int y) { // ㅗ 모양
	int tmp_sum = 0;
	tmp_sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x - 1][y + 1];
	if (tmp_sum > mx) mx = tmp_sum;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(check, false, sizeof(check));
			dfs(i, j, 0, 0);
			if (i < n - 2 && j < m - 1) type1(i, j);
			if (i < n - 2 && j > 0) type2(i, j);
			if (i < n - 1 && j < m - 2) type3(i, j);
			if (i > 0 && j < m - 2) type4(i, j);
		}
	}


	cout << mx;
	return 0;

}