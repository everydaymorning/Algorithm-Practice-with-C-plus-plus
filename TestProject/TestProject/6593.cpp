#include <bits/stdc++.h>
using namespace std;
int L, R, C;
char building[31][31][31];
int dis[31][31][31];
bool check[31][31][31];

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1};
bool possible;
int bfs(int a, int b, int c) {
	check[a][b][c] = true;
	queue<tuple<int, int, int>> q;
	q.push({ a,b,c });
	dis[a][b][c] = 1;
	while (!q.empty()) {
		auto cur = q.front(); // (0,0,0)
		q.pop();
		int cur_z = get<0>(cur);
		int cur_x = get<1>(cur);
		int cur_y = get<2>(cur);
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];
			int nz = cur_z + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
			if (building[nz][nx][ny] == '#' || check[nz][nx][ny]) continue;
			q.push({ nz,nx,ny });
			check[nz][nx][ny] = true;
			dis[nz][nx][ny] = dis[cur_z][cur_x][cur_y] + 1;
			if (building[nz][nx][ny] == 'E') {
				return dis[nz][nx][ny] - 1;
			
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) return 0;
		memset(check, false, sizeof(check));
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						x = i;
						y = j;
						z = k;
					}
					
				}
			}
		}
		int res = bfs(x, y, z);
		if (res == -1) {
			cout << "Trapped!" << '\n';
		}
		else {
			cout << "Escaped in " << res << " minute(s)." << '\n';
		}
	}

	return 0;
}