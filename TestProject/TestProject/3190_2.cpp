#include <bits/stdc++.h>
using namespace std;
int MAP[101][101];
int n, k, L;
int CNT, idx, dir, x, y;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int, char>> v;
deque<pair<int, int>> dq;

void INPUT() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		MAP[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int cnt;
		char dir;
		cin >> cnt >> dir;
		v.push_back({ cnt, dir });
	}
	MAP[0][0] = 2;
	dq.push_back({ 0,0 });
}

void move() {
	while (1) {
		CNT++;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (MAP[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= n || ny >= n)) break;

		if (MAP[nx][ny] == 0) {
			MAP[nx][ny] = 2;
			dq.push_front({ nx,ny });
			MAP[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else if (MAP[nx][ny] == 1) {
			MAP[nx][ny] = 2;
			dq.push_front({ nx,ny });
		}

		if (idx < v.size()) {
			if (CNT == v[idx].first) {
				if (v[idx].second == 'L') {
					dir = (dir + 1) % 4;
				}
				else if (v[idx].second == 'D') {
					dir = (dir + 3) % 4;
				}
				idx++;
			}
		}
		x = nx;
		y = ny;
	}
	cout << CNT;
}
void solve() {
	INPUT();
	move();
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}