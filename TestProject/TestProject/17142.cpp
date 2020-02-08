#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[51][51];
int TEMP[51][51];
int dist[51][51];
bool check[51][51];
bool virus_check[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool flag;
int res = 2147483647;
vector<pair<int, int>> virus, tmp_virus;
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == 1) {
				TEMP[i][j] = -1;
			}
			if (MAP[i][j] == 2) {
				TEMP[i][j] = 0; // 비활성화 바이러스
			}
		}
	}
}
void bfs() {
	int mx = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < tmp_virus.size(); i++) {
		int x = tmp_virus[i].first;
		int y = tmp_virus[i].second;
		q.push({ x,y });
		check[x][y] = true;
		TEMP[x][y] = 2;
	}

	while (!q.empty()) {
		int q_size = q.size();

		while (q_size--) {
			int virus_x = q.front().first;
			int virus_y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = virus_x + dx[dir];
				int ny = virus_y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny] || TEMP[nx][ny] == -1) continue;
				dist[nx][ny] = dist[virus_x][virus_y] + 1;
				TEMP[nx][ny] = 2;
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		dist[x][y] = -9;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, dist[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (TEMP[i][j] == 0) {
				flag = true;
			}
		}
	}
	if(!flag) res = min(res, mx);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		setting();
		bfs();
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(TEMP, 0, sizeof(TEMP));
		flag = false;
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (virus_check[i]) continue;
		virus_check[i] = true;
		tmp_virus.push_back({ virus[i] });
		dfs(i, cnt + 1);
		tmp_virus.pop_back();
		virus_check[i] = false;
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	if (res == 2147483647) {
		cout << "-1";
	}
	else {
		cout << res;
	}

	return 0;
}