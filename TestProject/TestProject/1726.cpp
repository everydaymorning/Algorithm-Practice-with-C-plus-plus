#include <bits/stdc++.h>
using namespace std;
int m, n, s_x, s_y, s_d, e_x, e_y, e_d;
int MAP[101][101];
bool check[101][101][5];
int dx[4] = { 0,0,1,-1 }; //�� �� �� ��
int dy[4] = { 1,-1,0,0 };
void bfs() {
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {s_x,s_y}, {s_d, 0 } });
	check[s_x][s_y][s_d] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		//cout << "x: " << x << "  y: " << y << " d: " << d << "  cnt: " << cnt << '\n';
		if (x == e_x && y == e_y && d == e_d) {
			cout << cnt;
			return;
		}

		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[d - 1] * i;
			int ny = y + dy[d - 1] * i;
			if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
			if (check[nx][ny][d]) continue;
			if (MAP[nx][ny]) break;
			check[nx][ny][d] = true;
			q.push({ {nx,ny}, {d, cnt + 1} });
			//cout << "nx: " << nx << " ny: " << ny << " d: " << d << '\n';
		}

		for (int i = 1; i <= 4; i++) { // 4���� ȸ��
			if (d != i && !check[x][y][i]) {
				check[x][y][i] = true;
				if ((d == 1 && i == 2) || (d == 2 && i == 1) || (d == 3 && i == 4) || (d == 4 && i == 3)) {
					q.push({ {x,y},{i, cnt + 2} });
					//cout << "180�� ȸ�� x: " << x << "  y: " << y << " i: " << i << "  cnt: " << cnt << '\n';
				}
				else {
					q.push({ {x,y},{i, cnt + 1} });
					//cout << "90�� ȸ�� x: " << x << "  y: " << y << " i: " << i << "  cnt: " << cnt << '\n';

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