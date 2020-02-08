#include <bits/stdc++.h>
using namespace std;

char MAP[11][11];
bool check[11][11][11][11];
int dx[4] = { -1,1,0,0 }; // »ó ÇÏ ÁÂ ¿ì
int dy[4] = { 0,0,-1,1 };
int cnt;
int n, m;
int red_x, red_y, blue_x, blue_y, es_x, es_y;
bool flag;
queue<pair<int, int>> red_q;
queue<pair<int, int>> blue_q;
void bfs() {
	while (!red_q.empty()) {

		int q_size = red_q.size();

		cout << "q_size: " << q_size << '\n';
		while (q_size--) {
			auto red_cur = red_q.front();
			red_x = red_cur.first;
			red_y = red_cur.second;
			cout << "red_x: " << red_x << " red_y: " << red_y << '\n';
			red_q.pop();
			auto blue_cur = blue_q.front();
			blue_x = blue_cur.first;
			blue_y = blue_cur.second;
			blue_q.pop();

			if (cnt > 10) {
				break;
			}

			if (red_x == es_x && red_y == es_y) {
				//cout << "es_x: " << es_x << " es_y: " << es_y << '\n';
				cout << "1";
				return;
			}
			for (int dir = 0; dir < 4; dir++) {

				int red_nx = red_x + dx[dir];
				int red_ny = red_y + dy[dir];

				int blue_nx = blue_x + dx[dir];
				int blue_ny = blue_y + dy[dir];

				while (1) {
					if (MAP[red_nx][red_ny] == '#') {
						red_nx -= dx[dir];
						red_ny -= dy[dir];
						break;
					}
					if (MAP[red_nx][red_ny] == 'O') {
						break;
					}
					red_nx += dx[dir];
					red_ny += dy[dir];

				}
				cout << "dir: " << dir << " red_nx: " << red_nx << "   red_ny: " << red_ny << '\n';
				while (1) {
					if (MAP[blue_nx][blue_ny] == '#') {
						blue_nx -= dx[dir];
						blue_ny -= dy[dir];
						break;
					}
					if (MAP[blue_nx][blue_ny] == 'O') {
						break;
					}
					blue_nx += dx[dir];
					blue_ny += dy[dir];
				}
				cout << "dir: " << dir << "  blue_nx: " << blue_nx << "   blue_ny: " << blue_ny << '\n';

				if (blue_nx == es_x && blue_ny == es_y) continue;

				if (red_nx == blue_nx && red_ny == blue_ny) {
					switch (dir) {
					case 0: red_x > blue_x ? red_nx++ : blue_nx++; break; // »ó
					case 1: red_x < blue_x ? red_nx-- : blue_nx--; break; // ÇÏ
					case 2: red_y > blue_y ? red_ny++ : blue_ny++; break; // ÁÂ
					case 3: red_y < blue_y ? red_ny-- : blue_ny--; break; // ¿ì
					}
					//cout << "°ãÃÆÀ» ¶§: " << "  red_nx: " << red_nx << "   red_ny: " << red_ny << "  blue_nx: " << blue_nx << "   blue_ny: " << blue_ny << '\n';
				}

				if (check[red_nx][red_ny][blue_nx][blue_ny]) continue;
				red_q.push({ red_nx, red_ny });
				blue_q.push({ blue_nx, blue_ny });
				cout << "dir: " << dir << " red_nx: " << red_nx << "   red_ny: " << red_ny << '\n';
				cout << "dir: " << dir << "  blue_nx: " << blue_nx << "   blue_ny: " << blue_ny << '\n';
				check[red_nx][red_ny][blue_nx][blue_ny] = true;
			}
		}
		cnt++;
		cout << "cnt: " << cnt << '\n';
	}
	cout << "0";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			if (MAP[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
			if (MAP[i][j] == 'O') {
				es_x = i;
				es_y = j;
			}
		}
	}
	check[red_x][red_y][blue_x][blue_y] = true;
	red_q.push({ red_x, red_y });
	blue_q.push({ blue_x, blue_y });
	bfs();
	return 0;
}