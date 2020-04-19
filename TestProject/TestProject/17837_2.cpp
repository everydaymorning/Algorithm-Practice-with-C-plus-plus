#include <bits/stdc++.h>
using namespace std;
struct chess {
	int x;
	int y;
	int dir;
};
int n, k;
int MAP[13][13];
chess knight[11];
vector<int> TEMP[13][13];
int dx[5] = {0, 0,0,-1,1 };
int dy[5] = {0, 1,-1,0,0 };
int ans;
bool flag;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		knight[i].x = x;
		knight[i].y = y;
		knight[i].dir = dir;
		TEMP[x][y].push_back(i);
	}
	while (1) {
		if (ans > 1000) {
			break;
		}

		for (int i = 1; i <= k; i++) {
			int x = knight[i].x;
			int y = knight[i].y;
			int dir = knight[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx > 0 && ny > 0 && nx <= n && ny <= n && MAP[nx][ny] != 2) {
				if (MAP[nx][ny] == 0) { // 흰색인 경우
					int loc = 0;
					for (int j = 0; j < TEMP[x][y].size(); j++) {
						if (TEMP[x][y][j] == i) loc = j;
					}

					for (int j = loc; j < TEMP[x][y].size(); j++) {
						int tmp = TEMP[x][y][j];
						TEMP[nx][ny].push_back(tmp);
						knight[tmp].x = nx;
						knight[tmp].y = ny;
					}
					int cnt = 0;
					for (int j = TEMP[x][y].size() - 1; j >= 0; j--) {
						cnt++;
						if (TEMP[x][y][j] == i) break;
					}

					for (int j = 0; j < cnt; j++) {
						TEMP[x][y].pop_back();
					}
				}
				else if (MAP[nx][ny] == 1) { // 빨간색인 경우
					int loc = 0;
					for (int j = 0; j < TEMP[x][y].size(); j++) {
						if (TEMP[x][y][j] == i) loc = j;
					}

					for (int j = TEMP[x][y].size() - 1; j >= loc; j--) {
						int tmp = TEMP[x][y][j];
						TEMP[nx][ny].push_back(tmp);
						knight[tmp].x = nx;
						knight[tmp].y = ny;
					}
					int cnt = 0;
					for (int j = TEMP[x][y].size() - 1; j >= 0; j--) {
						cnt++;
						if (TEMP[x][y][j] == i) break;
					}

					for (int j = 0; j < cnt; j++) {
						TEMP[x][y].pop_back();
					}
				}
			}
			if (MAP[nx][ny] == 2 || (nx < 1 || ny < 1 || nx > n || ny > n)) { // 파란색이거나 범위를 벗어난 경우
				if (knight[i].dir == 1) knight[i].dir = 2;
				else if (knight[i].dir == 2) knight[i].dir = 1;
				else if (knight[i].dir == 3) knight[i].dir = 4;
				else if (knight[i].dir == 4) knight[i].dir = 3;

				dir = knight[i].dir;
				nx = x + dx[dir];
				ny = y + dy[dir];


				if (MAP[nx][ny] != 2 && (nx > 0 && ny > 0 && nx <= n && ny <= n)) {
					if (MAP[nx][ny] == 0) {
						int loc = 0;
						for (int j = 0; j < TEMP[x][y].size(); j++) {
							if (TEMP[x][y][j] == i) loc = j;
						}

						for (int j = loc; j < TEMP[x][y].size(); j++) {
							int tmp = TEMP[x][y][j];
							TEMP[nx][ny].push_back(tmp);
							knight[tmp].x = nx;
							knight[tmp].y = ny;
						}
						int cnt = 0;
						for (int j = TEMP[x][y].size() - 1; j >= 0; j--) {
							cnt++;
							if (TEMP[x][y][j] == i) break;
						}

						for (int j = 0; j < cnt; j++) {
							TEMP[x][y].pop_back();
						}
					}
					else if (MAP[nx][ny] == 1) {
						int loc = 0;
						for (int j = 0; j < TEMP[x][y].size(); j++) {
							if (TEMP[x][y][j] == i) loc = j;
						}

						for (int j = TEMP[x][y].size() - 1; j >= loc; j--) {
							int tmp = TEMP[x][y][j];
							TEMP[nx][ny].push_back(tmp);
							knight[tmp].x = nx;
							knight[tmp].y = ny;
						}
						int cnt = 0;
						for (int j = TEMP[x][y].size() - 1; j >= 0; j--) {
							cnt++;
							if (TEMP[x][y][j] == i) break;
						}

						for (int j = 0; j < cnt; j++) {
							TEMP[x][y].pop_back();
						}
					}
				}
				

			}

			for (int j = 1; j <= k; j++) {
				int x = knight[j].x;
				int y = knight[j].y;

				if (TEMP[x][y].size() >= 4) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
		ans++;
	}
	if (flag) cout << ans + 1;
	else cout << "-1";
	return 0;
}