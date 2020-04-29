#include <bits/stdc++.h>
using namespace std;
int MAP[51][51];
bool check[51][51];
int n, m, x, y, d, cnt;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
void INPUT() {
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
}
void move() {
	while (1) {
		if (!check[x][y]) {
			check[x][y] = true;
			cnt++;
		}
		bool flag = false;
		for (int dir = 0; dir < 4; dir++) {
			d = (d + 3) % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (MAP[nx][ny] == 1 || check[nx][ny]) continue;
			x = nx;
			y = ny;
			flag = true;
			break;
		}
		if (!flag) {
			x = x + dx[(d + 2) % 4];
			y = y + dy[(d + 2) % 4];
			if (MAP[x][y] == 1) break;
		}
	}
	cout << cnt;
}
void solve() {
	INPUT();
	move();
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}