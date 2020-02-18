#include <bits/stdc++.h>
using namespace std;
int r, c, m, cnt;
struct Shark {
	int x;
	int y;
	int s;
	int d;
	int z;
	int num;
};
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };
vector<Shark> shark;
vector<int> shark_loc[101][101];

bool cmp(int a, int b) {
	return shark[a].z > shark[b].z;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		shark.push_back({ x,y,s,d,z,i });
		shark_loc[x][y].push_back(i);
	}

	for (int i = 1; i <= c; i++) {
		bool flag = false;

		for (int j = 0; j < shark.size(); j++) {
			if (shark[j].z != 0) {
				flag = true;
				break;
			}
		}
		if (!flag) break;

		for (int j = 1; j <= r; j++) {
			if (shark_loc[j][i].size() > 0) {
				cnt += shark[shark_loc[j][i][0]].z;
				shark[shark_loc[j][i][0]].z = 0;
				shark_loc[j][i].clear();
				break;
			}
		}

		for (int j = 0; j < shark.size(); j++) {
			if (shark[j].z == 0) continue;
			int x = shark[j].x;
			int y = shark[j].y;
			shark_loc[x][y].clear();

		}

		for (int j = 0; j < shark.size(); j++) {
			if (shark[j].z == 0) continue;
			int x = shark[j].x;
			int y = shark[j].y;
			int s = shark[j].s;
			int d = shark[j].d;

			if (d == 1 || d == 2) {
				int dis = (r - 1) * 2;
				if (s >= dis) s = s % dis;

				for (int k = 0; k < s; k++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx < 1) {
						d = 2;
						nx += 2;
					}
					else if (nx > r) {
						d = 1;
						nx -= 2;
					}
					x = nx;
					y = ny;
				}
			}
			else {
				int dis = (c - 1) * 2;
				if (s >= dis) s = s % dis;

				for (int k = 0; k < s; k++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (ny < 1) {
						d = 3;
						ny += 2;
					}
					else if (ny > c) {
						d = 4;
						ny -= 2;
					}
					x = nx;
					y = ny;
				}
			}

			shark[j].x = x;
			shark[j].y = y;
			shark[j].d = d;
			shark_loc[x][y].push_back(j);
		}


		for (int j = 1; j <= r; j++) {
			for (int k = 1; k <= c; k++) {
				if (shark_loc[j][k].size() > 1) {
					sort(shark_loc[j][k].begin(), shark_loc[j][k].end(), cmp);
					int big_shark_idx = shark_loc[j][k][0];
					for (int L = 1; L < shark_loc[j][k].size(); L++) {
						shark[shark_loc[j][k][L]].z = 0;
						shark[shark_loc[j][k][L]].x = -1;
						shark[shark_loc[j][k][L]].y = -1;
					}
					shark_loc[j][k].clear();
					shark_loc[j][k].push_back(shark[big_shark_idx].num);
				}
			}
		}
	}
	cout << cnt;
	return 0;
}