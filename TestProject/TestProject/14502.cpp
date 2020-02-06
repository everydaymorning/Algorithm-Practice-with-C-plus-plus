#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[9][9];
int TEMP[9][9];
bool check[9][9];
bool virus_check[9][9];
int mx;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> virus, virus2;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void bfs() {
	int cnt = 0;
	virus = virus2;
	while (!virus.empty()) {
		int virus_x = virus.front().first;
		int virus_y = virus.front().second;
		virus_check[virus_x][virus_y] = true;
		virus.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = virus_x + dx[dir];
			int ny = virus_y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (TEMP[nx][ny] == 1 || virus_check[nx][ny]) continue;
			TEMP[nx][ny] = 2;
			virus_check[nx][ny] = true;
			virus.push({ nx ,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (TEMP[i][j] == 0) {
				cnt++;
			}
		}
	}
	mx = max(mx, cnt);
}
void dfs(int a, int b, int cnt) {
	if (cnt == 3) {
		copy();
		bfs();
		memset(virus_check, false, sizeof(virus_check));
		return;
	}

	for (int i = a; i < n; i++) {
		int y = 0;
		if (i == a) y = b;
		for (int j = y; j < m; j++) {
			if (check[i][j] || MAP[i][j] == 2 || MAP[i][j] == 1) continue;
			check[i][j] = true;
			MAP[i][j] = 1;
			dfs(i, j + 1, cnt + 1);
			MAP[i][j] = 0;
			check[i][j] = false;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push({ i,j });
			}
		}
	}
	virus2 = virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 0);
		}
	}

	cout << mx;
	return 0;
}