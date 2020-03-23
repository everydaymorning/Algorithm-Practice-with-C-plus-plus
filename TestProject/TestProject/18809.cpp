#include <bits/stdc++.h>
using namespace std;
int n, m, g, r;
int MAP[51][51];
bool check[11];
int green[5];
int red[5];
int MAX;
vector<pair<int, int>> pos;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int pos_size;

void bfs() {
	pair<int, int> tmp[51][51];
	queue<pair<int, int>> q; // TIME, COLOR;
	int cnt = 0;
	for (int i = 0; i < g; i++) {
		tmp[pos[green[i]].first][pos[green[i]].second] = { 0,1 };
		q.push(pos[green[i]]);
	}
	
	for (int i = 0; i < r; i++) {
		tmp[pos[red[i]].first][pos[red[i]].second] = { 0,2 };
		q.push(pos[red[i]]);
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int TIME = tmp[x][y].first;
		int COLOR = tmp[x][y].second;
		if (tmp[x][y].second == 3) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (MAP[nx][ny] == 0) continue;
			if (tmp[nx][ny].second == 1) {
				if (COLOR == 2 && tmp[nx][ny].first == TIME + 1) {
					//tmp[nx][ny].first = TIME + 1;
					tmp[nx][ny].second = 3;
					cnt++;
				}
			}
			else if (tmp[nx][ny].second == 2) {
				if (COLOR == 1 && tmp[nx][ny].first == TIME + 1) {
					//tmp[nx][ny].first = TIME + 1;
					tmp[nx][ny].second = 3;
					cnt++;
				}
			}
			else if(tmp[nx][ny].second == 0){
				tmp[nx][ny] = { TIME + 1, COLOR };
				q.push({ nx, ny });
			}
		}
	}

	MAX = max(cnt, MAX);
}
void dfs_r(int idx) {
	if (idx == r) {
		bfs();
		return;
	}

	int cur = 0;
	if (idx != 0) cur = red[idx - 1] + 1;

	while (cur < pos_size) {
		if (check[cur]) {
			cur++;
			continue;
		}
		check[cur] = true;
		red[idx] = cur;
		dfs_r(idx + 1);
		check[cur] = false;
		cur++;
	}
}
void dfs_g(int idx) {
	if (idx == g) {
		dfs_r(0);
		return;
	}

	int cur = 0;
	if (idx != 0) cur = green[idx - 1] + 1;

	while (cur < pos_size) {
		check[cur] = true;
		green[idx] = cur;
		dfs_g(idx + 1);
		check[cur] = false;
		cur++;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) pos.push_back({i,j});
		}
	}
	pos_size = pos.size();
	dfs_g(0);
	cout << MAX;
	return 0;
}