#include <bits/stdc++.h>
using namespace std;

string miro[102];
int dist[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		cin >> miro[i];
	}

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || miro[nx][ny] != '1') continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push(make_pair(nx, ny));
			
		}
	}

	cout << dist[n - 1][m - 1] + 1;
	

	return 0;
}