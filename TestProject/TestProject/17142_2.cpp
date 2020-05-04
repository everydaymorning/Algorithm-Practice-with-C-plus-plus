#include <bits/stdc++.h>
using namespace std;
const int MAX = 2147483647;
int n, m;
int MAP[51][51];
int TEMP[51][51];
int dist[51][51];
bool check[51][51];
bool visit[11];
vector<pair<int, int>> virus, tmp;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int MAX_TMP;
int ans = MAX;
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TEMP[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}
void bfs() {
	MAX_TMP = 0;
	queue<pair<pair<int,int>, int>> q;
	for (int i = 0; i < tmp.size(); i++) {
		int x = tmp[i].first;
		int y = tmp[i].second;
		q.push({ {x,y},0 });
		check[x][y] = true;
		TEMP[x][y] = 2;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny] || TEMP[nx][ny] == -2) continue;
			if (TEMP[x][y] >= 0 && (TEMP[x][y] < TEMP[nx][ny])) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ {nx,ny}, cnt + 1 });
			check[nx][ny] = true;
			TEMP[nx][ny] = 2;
		}
	}

	for (int i = 0; i < virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		dist[x][y] = -5;
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MAX_TMP = max(MAX_TMP, dist[i][j]);
		}
	}
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (TEMP[i][j] == 0) {
				flag = true;
			}
		}
	}
	if (!flag) ans = min(ans, MAX_TMP);
}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] == 1) TEMP[i][j] = -2;
			if (MAP[i][j] == 2) TEMP[i][j] = 0;
		}
	}
}
void dfs(int cnt, int idx) {
	if (cnt == m) {
		setting();
		bfs();
		memset(check, false, sizeof(check));
		copy();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		tmp.push_back(virus[i]);
		dfs(cnt + 1, i);
		tmp.pop_back();
		visit[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) virus.push_back({ i,j });
		}
	}
	dfs(0, 0);
	if (ans == MAX) cout << "-1";
	else cout << ans;
	return 0;


}