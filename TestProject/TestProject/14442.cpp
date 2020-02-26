#include <bits/stdc++.h>
using namespace std;
int MAP[1001][1001];
int check[1001][1001][11];
int n, m, k;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	check[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << check[x][y][block];
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny][block]) continue;
			if (MAP[nx][ny] == 0) {
				q.push({ {nx,ny},block });
				check[nx][ny][block] = check[x][y][block] + 1;
			}
			else if (MAP[nx][ny] == 1 && block < k) {
				q.push({ {nx,ny}, block + 1 });
				check[nx][ny][block + 1] = check[x][y][block] + 1;
			}
		}
	}
	cout << "-1";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < m; j++) {
			MAP[i][j] = tmp[j] - '0';
		}
	}

	bfs();
	return 0;
}