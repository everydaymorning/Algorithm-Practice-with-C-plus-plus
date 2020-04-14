#include <bits/stdc++.h>
using namespace std;
struct chess {
	int x;
	int y;
	int dir;
};

int MAP[13][13];
int n, k, ans;
vector<int> TEMP[13][13];
chess knight[11];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

void move(int x, int y, int nx, int ny, int loc, int color, int num) {
	if (color == 0) {
		for (int i = loc; i < TEMP[x][y].size(); i++) {
			int idx = TEMP[x][y][i];
			TEMP[nx][ny].push_back(idx);
			knight[idx].x = nx;
			knight[idx].y = ny;
		}
		int cnt = 0;
		for (int i = TEMP[x][y].size() - 1; i >= 0; i--) {
			cnt++;
			if (TEMP[x][y][i] == num) break;
		}

		for (int i = 0; i < cnt; i++) {
			TEMP[x][y].pop_back();
		}
	}
	else if (color == 1) {
		for (int i = TEMP[x][y].size() - 1; i >= loc; i--) {
			int idx = TEMP[x][y][i];
			TEMP[nx][ny].push_back(idx);
			knight[idx].x = nx;
			knight[idx].y = ny;
		}

		int cnt = 0;
		for (int i = TEMP[x][y].size() - 1; i >= 0; i--) {
			cnt++;
			if (TEMP[x][y][i] == num) break;
		}

		for (int i = 0; i < cnt; i++) {
			TEMP[x][y].pop_back();
		}
	}
	else if (color == 2) {
		if (knight[num].dir == 1) knight[num].dir = 2;
		else if (knight[num].dir == 2) knight[num].dir = 1;
		else if (knight[num].dir == 3) knight[num].dir = 4;
		else if (knight[num].dir == 4) knight[num].dir = 3;
		int dir = knight[num].dir;
		int nx1 = x + dx[dir];
		int ny1 = y + dy[dir];

		if (nx1 > 0 && ny1 > 0 && nx1 <= n && ny1 <= n) {
			if (MAP[nx1][ny1] != 2) move(x, y, nx1, ny1, loc, MAP[nx1][ny1], num);
		}
	}
}
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
	bool flag = false;

	while (1) {

		if (ans > 1000) break;

		for (int i = 1; i <= k; i++) {
			int x = knight[i].x;
			int y = knight[i].y;
			int dir = knight[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int loc = 0;
			for (int j = 0; j < TEMP[x][y].size(); j++) {
				if (TEMP[x][y][j] == i) {
					loc = j;
					break;
				}
			}
			if (nx > 0 && ny > 0 && nx <= n && ny <= n) move(x, y, nx, ny, loc, MAP[nx][ny], i);
			else move(x, y, nx, ny, loc, 2, i);

			for (int j = 1; j <= k; j++) {
				int x = knight[j].x;
				int y = knight[j].y;
				if (TEMP[x][y].size() >= 4) {
					flag = true;
					break;
				}
			}
		}
		if (flag) break;
		ans++;
	}
	if (flag) {
		cout << ans + 1;
	}
	else cout << "-1";
	return 0;
}