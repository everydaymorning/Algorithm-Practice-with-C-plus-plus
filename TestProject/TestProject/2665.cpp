#include <bits/stdc++.h>
using namespace std;
int MAP[51][51];
int dist[51][51];

int n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (MAP[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y]) {
					q.push({ nx,ny });
					dist[nx][ny] = dist[x][y];
				}
			}
			else if (MAP[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					q.push({ nx,ny });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			MAP[i][j] = str[j] - '0';
			dist[i][j] = 987654321;
		}
	}
	dist[0][0] = 0;
	bfs();
	cout << dist[n - 1][n - 1];
	return 0;
}