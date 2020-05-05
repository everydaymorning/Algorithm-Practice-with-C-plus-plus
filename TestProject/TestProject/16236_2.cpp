#include <bits/stdc++.h>
using namespace std;
int MAP[21][21];
bool check[21][21];
int n;
struct baby {
	int x;
	int y;
	int size;
	int eat_num;
	int dist;
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
baby baby_shark;
vector<pair<pair<int, int>, pair<int, int>>> v;

bool cmp(pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2) {
	if (p1.second.second == p2.second.second) {
		if (p1.first.first == p2.first.first) {
			return p1.first.second < p2.first.second;
		}
		return p1.first.first < p2.first.first;
	}
	return p1.second.second < p2.second.second;
}
bool bfs() {
	int x = baby_shark.x;
	int y = baby_shark.y;
	int size = baby_shark.size;
	bool flag = false;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x,y},{0} });
	check[x][y] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (check[nx][ny]) continue;
			if (size < MAP[nx][ny]) continue;
			if (size > MAP[nx][ny] && MAP[nx][ny] != 0) {
				v.push_back({ {nx,ny},{MAP[nx][ny], cnt + 1} });
				flag = true;
			}
			q.push({ {nx,ny},{cnt + 1} });
			check[nx][ny] = true;
		}
	}
	if (flag) {
		sort(v.begin(), v.end(), cmp);
		baby_shark.x = v[0].first.first;
		baby_shark.y = v[0].first.second;
		baby_shark.dist += v[0].second.second;
		baby_shark.eat_num++;
		if (baby_shark.eat_num >= baby_shark.size) {
			baby_shark.eat_num = 0;
			baby_shark.size++;
		}
		MAP[v[0].first.first][v[0].first.second] = 0;
		v.clear();
		return true;
	}
	return false;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				baby_shark.x = i;
				baby_shark.y = j;
				baby_shark.size = 2;
				baby_shark.eat_num = 0;
				baby_shark.dist = 0;
				MAP[i][j] = 0;
			}
		}
	}

	while (1) {
		memset(check, false, sizeof(check));
		if (!bfs()) {
			cout << baby_shark.dist;
			break;
		}
	}
	return 0;
}