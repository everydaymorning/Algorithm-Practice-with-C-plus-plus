#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, d;
int MAP[51][51];
bool check[51][51];
int dx[4] = { -1,0,1,0 }; // 북 동 남 서
int dy[4] = { 0,1,0,-1 };
int cnt = 0;

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r,c},d });
	check[r][c] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		cnt++; // 1번 조건, 현재 위치 청소
		//cout << "x: " << x << " y: " << y << " dir: " << dir << '\n';
		bool flag = false;
		for (int i = 0; i < 4; i++) { // 2번 조건, 왼쪽 방향부터 차례대로 탐색
			dir = (dir + 3) % 4; // 왼쪽 방향 처리
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (MAP[nx][ny] == 1 || check[nx][ny]) continue;
			q.push({ {nx,ny},dir });

			check[nx][ny] = true;
			flag = true;
			break;
		}
		if (!flag) {
			dir = (dir + 2) % 4; // 후진 (반대 방향 처리)
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (MAP[nx][ny] == 1) return;
			q.push({ {nx,ny}, (dir + 2) % 4 });
			cnt--;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	bfs();
	cout << cnt;
	return 0;
}