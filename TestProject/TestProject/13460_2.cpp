#include <bits/stdc++.h>
using namespace std;
char MAP[11][11];
int hole_x, hole_y;
int n, m;
queue<pair<int, int>> red_q, blue_q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool check[11][11][11][11];
int cnt;
void bfs() {
	
	while (!red_q.empty()) {
		int red_size = red_q.size();

		while (red_size--) {
			int rx = red_q.front().first;
			int ry = red_q.front().second;
			red_q.pop();

			int bx = blue_q.front().first;
			int by = blue_q.front().second;
			blue_q.pop();
			check[rx][ry][bx][by] = true;

			if (cnt > 10) break;
			if (rx == hole_x && ry == hole_y) {
				cout << cnt;
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nrx = rx + dx[dir];
				int nry = ry + dy[dir];
				int nbx = bx + dx[dir];
				int nby = by + dy[dir];

				while (1) {
					if (MAP[nrx][nry] == '#') {
						nrx -= dx[dir];
						nry -= dy[dir];
						break;
					}
					if (MAP[nrx][nry] == 'O') {
						break;
					}
					nrx += dx[dir];
					nry += dy[dir];
				}

				while (1) {
					if (MAP[nbx][nby] == '#') {
						nbx -= dx[dir];
						nby -= dy[dir];
						break;
					}
					if (MAP[nbx][nby] == 'O') {
						break;
					}
					nbx += dx[dir];
					nby += dy[dir];
				}

				if (nbx == hole_x && nby == hole_y) continue;
				if (nrx == nbx && nry == nby) {
					switch (dir) {
					case 0: // ¼­ÂÊ
						if (ry < by) nby++;
						else nry++;
						break;
					case 1:
						if (ry < by) nry--;
						else nby--;
						break;
					case 2:
						if (rx < bx) nbx++;
						else nrx++;
						break;
					case 3:
						if (rx < bx) nrx--;
						else nbx--;
					}
					
				}

				if (check[nrx][nry][nbx][nby]) continue;
				red_q.push({ nrx,nry });
				blue_q.push({ nbx,nby });
				check[nrx][nry][nbx][nby] = true;
			}
		}
		cnt++;

	}
	cout << "-1";
}
void INPUT() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			MAP[i][j] = s[j];
			if (MAP[i][j] == 'R') {
				red_q.push({ i,j });
			}
			else if (MAP[i][j] == 'B') {
				blue_q.push({ i,j });
			}
			else if (MAP[i][j] == 'O') {
				hole_x = i;
				hole_y = j;
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	INPUT();
	bfs();
	return 0;
}