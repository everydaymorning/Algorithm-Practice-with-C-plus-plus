#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[1001][1001];
int check[1001][1001][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},0 });
	check[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();
		if (x == n-1 && y == m-1) {
			cout << check[x][y][block];
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny][block]) continue;
			if (MAP[nx][ny] == 0) {
				//cout << "길을 갈 수 있을 때 현재 위치 x: " << x << " y: " << y << " block: " << block <<  '\n';
				check[nx][ny][block] = check[x][y][block] + 1;
				q.push({ {nx,ny},block });
			}
			else if (MAP[nx][ny] == 1 && block == 0) {
				//cout << "벽을 갈 수 있을 때 현재 위치 x: " << x << " y: " << y << " block: " << block << '\n';
				check[nx][ny][block + 1] = check[x][y][block] + 1;
				q.push({ {nx,ny},block + 1 });
			}
			
			
		}
		/*cout << "벽을 깨지 않은 상태" << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << check[i][j][0] << " ";
			}
			cout << '\n';
		}
		cout << "벽을 하나 깬 상태" << '\n';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << check[i][j][1] << " ";
			}
			cout << '\n';
		}*/
	}
	cout << "-1";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < m; j++) {
			MAP[i][j] = tmp[j] - '0';
		}
	}
	bfs();
	return 0;

}