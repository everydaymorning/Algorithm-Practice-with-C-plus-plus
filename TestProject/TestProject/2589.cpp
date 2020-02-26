#include <bits/stdc++.h>
using namespace std;
char MAP[51][51];
bool check[51][51];
int dist[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;
int mx;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = true;
	dist[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (MAP[nx][ny] == 'W' || check[nx][ny]) continue;
			q.push({ nx,ny });
			check[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			mx = max(mx, dist[nx][ny]);
		}
		
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			MAP[i][j] = tmp[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (MAP[i][j] == 'W') continue;
			bfs(i,j);
			memset(check, false, sizeof(check));
			memset(dist, 0, sizeof(dist));
		}
	}

	cout << mx;
	return 0;
}