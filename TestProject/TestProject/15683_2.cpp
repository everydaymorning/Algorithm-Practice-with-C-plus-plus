#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[10][10];
int TEMP[10][10];
vector<pair<int, int>> v;
vector<pair<pair<int, int>, int>> cctv;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int MIN = 2147483647;
void move(int x, int y, int dir) {
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (TEMP[nx][ny] == 6 || (nx < 0 || ny < 0 || nx >= n || ny >= m)) break;
		if (TEMP[nx][ny] >= 1 && TEMP[nx][ny] <= 5) {
			x = nx;
			y = ny;
			continue;
		}
		TEMP[nx][ny] = -1;
		x = nx;
		y = ny;
	}
}
void gamsi() {

	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].first.first;
		int y = cctv[i].first.second;
		int dir = cctv[i].second;

		if (TEMP[x][y] == 1) {
			move(x, y, dir);
		}
		else if (TEMP[x][y] == 2) {
			move(x, y, (dir) % 4);
			move(x, y, (dir + 2) % 4);

		}
		else if (TEMP[x][y] == 3) {
			move(x, y, (dir) % 4);
			move(x, y, (dir + 1) % 4);
		}
		else if (TEMP[x][y] == 4) {
			move(x, y, (dir) % 4);
			move(x, y, (dir + 1) % 4);
			move(x, y, (dir + 2) % 4);
		}
		else if (TEMP[x][y] == 5) {
			move(x, y, (dir) % 4);
			move(x, y, (dir + 1) % 4);
			move(x, y, (dir + 2) % 4);
			move(x, y, (dir + 3) % 4);
		}
	}

}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void count() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (TEMP[i][j] == 0) sum++;
		}
	}
	MIN = min(MIN, sum);

}
void dfs(int cnt) {
	if (cnt == v.size()) {
		setting();
		gamsi();
		count();
		return;
	}
	
	cctv.push_back({ {v[cnt].first, v[cnt].second}, 0 });
	dfs(cnt + 1);
	cctv.pop_back();

	cctv.push_back({ {v[cnt].first, v[cnt].second}, 1 });
	dfs(cnt + 1);
	cctv.pop_back();

	cctv.push_back({ {v[cnt].first, v[cnt].second}, 2 });
	dfs(cnt + 1);
	cctv.pop_back();

	cctv.push_back({ {v[cnt].first, v[cnt].second}, 3 });
	dfs(cnt + 1);
	cctv.pop_back();

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] != 0 && MAP[i][j] != 6) {
				v.push_back({ i,j });
			}
		}
	}
	dfs(0);

	cout << MIN;
	return 0;
}