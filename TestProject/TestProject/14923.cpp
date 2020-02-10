#include <bits/stdc++.h>
using namespace std;
const int MAX = 2147483647;
int n, m, hx, hy, ex, ey;
int MAP[1001][1001];
int check[1001][1001][2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {hx,hy}, 1 });
	check[hx][hy][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();
		cout << "현재위치   x: " << x << "  y: " << y << '\n';
		if (x == ex && y == ey) {
			cout << check[x][y][block] - 1;
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (MAP[nx][ny] == 1 && block > 0) {
				cout << "벽: " << "  nx: " << nx << "  ny: " << ny << "  block: " << block << '\n';

				q.push({ {nx,ny}, block - 1 });
				check[nx][ny][block - 1] = check[x][y][block] + 1;
			}
			else if (MAP[nx][ny] == 0 && check[nx][ny][block] == 0) {
				cout << "빈 곳: " << "  nx: " << nx << "  ny: " << ny << "  block: " << block << '\n';

				q.push({ {nx,ny}, block });
				check[nx][ny][block] = check[x][y][block] + 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << check[i][j][0] << " ";
			}
			cout << '\n';
		}
		cout << '\n';

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << check[i][j][1] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << "-1";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	cin >> hx >> hy;
	cin >> ex >> ey;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}
	bfs();

	return 0;
}