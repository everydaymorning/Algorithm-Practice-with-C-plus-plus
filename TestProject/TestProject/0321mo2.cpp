#include <bits/stdc++.h>
using namespace std;
int n, m, g, r;
int MAP[51][51];
int TEMP[51][51];
int dist1[51][51];
int dist2[51][51];
bool check[11];
bool visit[51][51][2];
int MAX;
vector<pair<int, int>> green, red, pos;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void bfs() {

	queue<pair<pair<int, int>, int>> gq;
	queue<pair<pair<int, int>, int>> rq;
	for (int i = 0; i < green.size(); i++) {
		int x = green[i].first;
		int y = green[i].second;
		//cout << "green_x: " << x << "  green_y: " << y << '\n';
		gq.push({ {x,y}, 0 });
		visit[x][y][0] = true;
	}

	for (int i = 0; i < red.size(); i++) {
		int x = red[i].first;
		int y = red[i].second;
		//cout << "red_x: " << x << "  red_y: " << y << '\n';

		gq.push({ {x,y}, 1 });
		visit[x][y][1] = true;
	}
	while (!gq.empty()) {

		int gq_size = gq.size();
		//cout << "gq_size: " << gq_size << "  rq_size: " << rq_size << '\n';
		
			int x = gq.front().first.first;
			int y = gq.front().first.second;
			int type = gq.front().second;
			gq.pop();
			//cout << "green_x: " << x << "  green_y: " << y << '\n';
			if (type == 0) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (TEMP[nx][ny] == 0 || TEMP[nx][ny] == 4 || visit[nx][ny][type]) continue;
					if (dist2[nx][ny] == dist1[x][y] + 1 && visit[nx][ny][1]) {
						TEMP[nx][ny] = 4;
						visit[nx][ny][type] = true;
						continue;
					}
					dist1[nx][ny] = dist1[x][y] + 1;
					gq.push({ {nx,ny}, type });
					visit[nx][ny][type] = true;
				}
			}
			else {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (TEMP[nx][ny] == 0 || TEMP[nx][ny] == 4 || visit[nx][ny][type]) continue;
					if (dist1[nx][ny] == dist2[x][y] + 1 && visit[nx][ny][0]) {
						TEMP[nx][ny] = 4;
						visit[nx][ny][type] = true;
						continue;
					}
					dist2[nx][ny] = dist2[x][y] + 1;
					gq.push({ {nx,ny}, type });
					visit[nx][ny][type] = true;
				}
			}
		


	}
	int tmp = 0;

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << TEMP[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (TEMP[i][j] == 4) tmp++;
		}
	}
	//cout << "tmp: " << tmp << '\n';
	MAX = max(tmp, MAX);
}
void dfs(int cnt, int g_cnt, int r_cnt) {
	//cout << "cnt: " << cnt << "  g_cnt: " << g_cnt << "  r_cnt: " << r_cnt << '\n';
	if (g + r == g_cnt + r_cnt) {
		setting();
		bfs();
		memset(visit, false, sizeof(visit));
		memset(dist1, 0, sizeof(dist1));
		memset(dist2, 0, sizeof(dist2));
		return;
	}

	for (int i = cnt; i < pos.size(); i++) {
		if (check[i]) continue;
		check[i] = true;

		if (g_cnt < g) {
			green.push_back(pos[i]);
			dfs(cnt + 1, g_cnt + 1, r_cnt);
			green.pop_back();

		}

		if (r_cnt < r) {

			red.push_back(pos[i]);
			dfs(cnt + 1, g_cnt, r_cnt + 1);
			red.pop_back();

		}
		check[i] = false;

	}
}
int main() {
	cin >> n >> m >> g >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) pos.push_back({i,j});
		}
	}

	dfs(0,0,0);
	
	cout << MAX;
	return 0;
}