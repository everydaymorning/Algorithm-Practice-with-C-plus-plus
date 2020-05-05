#include <bits/stdc++.h>
using namespace std;
int r, c, m;
int MAP[101][101];
int sum;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
struct shark {
	int num;
	int speed;
	int dir;
	int size;
};
bool check[10001];
deque<shark> TEMP[101][101];
bool cmp(shark s1, shark s2) {
	return s1.size > s2.size;
}
int change_direction(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}
int main() {
	cin >> r >> c >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		shark tmp;
		tmp.speed = s;
		tmp.dir = d;
		tmp.size = z;
		tmp.num = i;
		TEMP[x][y].push_back(tmp);
	}
	int idx = 0;
	while (1) {
		idx++;
		if (idx > c) break;
		for (int i = 1; i <= r; i++) {
			if (TEMP[i][idx].empty()) continue;
			sum += TEMP[i][idx][0].size;
			TEMP[i][idx].pop_back();
			break;
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (TEMP[i][j].empty()) continue;
				for (int k = 0; k < TEMP[i][j].size(); k++) {
					if (check[TEMP[i][j][k].num]) continue;
					int x = i;
					int y = j;
					int num = TEMP[i][j][k].num;
					int dir = TEMP[i][j][k].dir;
					int speed = TEMP[i][j][k].speed;
					int size = TEMP[i][j][k].size;
					if (dir == 1 || dir == 2) {
						int dis = (r - 1) * 2;
						if (speed >= dis) speed %= dis;
					}
					else if (dir == 3 || dir == 4) {
						int dis = (c - 1) * 2;
						if (speed >= dis) speed %= dis;
					}
					for (int e = 0; e < speed; e++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (nx < 1 || ny < 1 || nx > r || ny > c) {
							dir = change_direction(dir);
							nx = x + dx[dir];
							ny = y + dy[dir];
						}
						x = nx;
						y = ny;
					}
					TEMP[i][j].pop_back();
					shark tmp;
					tmp.num = num;
					tmp.dir = dir;
					tmp.size = size;
					tmp.speed = speed;
					check[num] = true;
					TEMP[x][y].push_front(tmp);
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (TEMP[i][j].empty()) continue;
				if (TEMP[i][j].size() > 1) {
					sort(TEMP[i][j].begin(), TEMP[i][j].end(), cmp);
					int size = TEMP[i][j].size();
					for (int k = 0; k < size - 1; k++) {
						TEMP[i][j].pop_back();
					}
				}
			}
		}
		memset(check, false, sizeof(check));
	}
	cout << sum;
	return 0;
}