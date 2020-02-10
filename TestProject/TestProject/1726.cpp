#include <bits/stdc++.h>
using namespace std;
int m, n, s_x, s_y, s_d, e_x, e_y, e_d;
int MAP[101][101];
bool check[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {s_x,s_y}, {s_d, 0 } });
	check[s_x][s_y] = true;

	while (!q.empty()) {


		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		//cout << "x: " << x << "  y: " << y << " d: " << d << "  cnt: " << cnt << '\n';
		if (x == e_x && y == e_y) {
			if (d != e_d) cout << cnt + 1;
			else cout << cnt;
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
			if (check[nx][ny] || MAP[nx][ny] == 1) continue;

			if (dir + 1 != d) {
				q.push({ {x,y},{dir + 1,cnt + 1} });
				//cout << "x: " << x << "  y: " << y << " 방향전환" << '\n';
			}
			else {

				switch (d) {
				case 1:
					for (int i = 1; i < 4; i++) {
						if (y + i <= n && MAP[nx][y + i] == 0) {
							q.push({ { nx,y + i }, { d,cnt + 1 } });
							check[nx][y + i] = true;
							//cout << "dir: " << dir << " d: " << d << "  nx: " << nx << "  y + " << i << " : " << y + i << '\n';
						}
					}
					break;

				case 2:
					for (int i = 1; i < 4; i++) {
						if (y - i >= 1 && MAP[nx][y - i] == 0) {
							q.push({ { nx,y - i }, { d,cnt + 1 } });
							check[nx][y - i] = true;
							//cout << "dir: " << dir << " d: " << d << "  nx: " << nx << "  y - " << i << " : " << y - i << '\n';
						}
					}
					break;
				case 3:
					for (int i = 1; i < 4; i++) {
						if (x + i <= m && MAP[x + i][ny] == 0) {
							q.push({ { x + i,ny }, { d,cnt + 1 } });
							check[x + i][ny] = true;
							//cout << "dir: " << dir << " d: " << d << "  x + " << i << " : " << x + i << "  ny: " << ny << '\n';
						}
					}
					break;

				case 4:
					for (int i = 1; i < 4; i++) {
						if (x - i >= 1 && MAP[x - i][ny] == 0) {
							q.push({ { x - i,ny }, { d,cnt + 1 } });
							check[x - i][ny] = true;
							//cout << "dir: " << dir << " d: " << d << "  x - " << i << " : " << x - i << "  ny: " << ny << '\n';
						}

					}
					break;

				}

			}
		}

	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}

	cin >> s_x >> s_y >> s_d;
	cin >> e_x >> e_y >> e_d;
	bfs();
	return 0;
}