#include <bits/stdc++.h>
using namespace std;
int n, m;
int res = 2147483647;
int MAP[51][51];
int TEMP[51][51];
int dist[51][51];
bool check[51][51];
bool virus_check[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool flag;
vector<pair<int, int>> virus;
vector<pair<int, int>> tmp_q;
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == 1) {
				TEMP[i][j] = -1;
			}
			if (MAP[i][j] == 2) {
				TEMP[i][j] = 0;
			}
		}
	}
}
void bfs() {
	int mx = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < tmp_q.size(); i++) {
		int virus_x = tmp_q[i].first;
		int virus_y = tmp_q[i].second;
		q.push({ virus_x, virus_y });
		check[virus_x][virus_y] = true;
	}

	while (!q.empty()) {
		int q_size = q.size();

		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			TEMP[x][y] = 2;
			check[x][y] = true;
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny] || TEMP[nx][ny] == -1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				TEMP[nx][ny] = 2;
				q.push({ nx,ny });
				check[nx][ny] = true;
				mx = max(mx, dist[nx][ny]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (TEMP[i][j] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) {
		res = min(res, mx);
	}

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
		tmp_q.push_back({ virus[i] });
		dfs(i, cnt + 1);
		tmp_q.pop_back();
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
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == 2) virus.push_back({ i,j });
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