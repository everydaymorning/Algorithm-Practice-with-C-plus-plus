#include <bits/stdc++.h>
using namespace std;
int MAP[8][8];
int TEMP[8][8];
bool check[8][8];
int n, m;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;
queue<pair<int, int>> virus;
int MAX;
void find_max() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (TEMP[i][j] == 0) sum++;
		}
	}
	MAX = max(MAX, sum);
}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void bfs() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		virus.push({ x,y });
		check[x][y] = true;
	}

	while (!virus.empty()) {
		int x = virus.front().first;
		int y = virus.front().second;
		virus.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (TEMP[nx][ny] == 2 || TEMP[nx][ny] == 1) continue;
			if (check[nx][ny]) continue;
			virus.push({ nx,ny });
			check[nx][ny] = true;
			TEMP[nx][ny] = 2;
		}
	}
}

void dfs(int cnt) {
	if (cnt == 3) {
		setting();
		bfs();
		memset(check, false, sizeof(check));
		find_max();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 0) {
				MAP[i][j] = 1;
				dfs(cnt + 1);
				MAP[i][j] = 0;
			}
		}
	}
}
void INPUT() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) v.push_back({ i,j });
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	INPUT();
	dfs(0);
	cout << MAX;
	return 0;
}