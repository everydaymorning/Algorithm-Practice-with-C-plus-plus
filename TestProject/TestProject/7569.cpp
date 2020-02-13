#include <bits/stdc++.h>
using namespace std;
int m, n, h;
bool check[101][101][101];
int MAP[101][101][101];
int res;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0, };
int dz[6] = { 0,0,0,0,-1,1 };
queue<pair<pair<int, int>, pair<int, int>>> q;


void bfs() {
	int mx = 0;
	bool all = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int d = q.front().second.second;
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nz = z + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (check[nz][nx][ny] || MAP[nz][nx][ny] != 0) continue;
			check[nz][nx][ny] = true;
			all = false;
			MAP[nz][nx][ny] = 1;
			q.push({ {nx,ny},{nz,d + 1} });
			mx = max(mx, d + 1);
		}
	}
	if (all) {
		cout << "0";
		return;
	}
	bool flag = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (MAP[i][j][k] == 0) {
					flag = true;
					break;
				}
			}
		}
	}
	if (flag) {
		cout << "-1";
		return;
	}
	else {
		cout << mx;
		return;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 1) {
					q.push({ {j,k},{i,0} });
					check[i][j][k] = true;
				}
			}
		}
	}
	bfs();
	return 0;
}