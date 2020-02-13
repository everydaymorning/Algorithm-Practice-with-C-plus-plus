#include <bits/stdc++.h>
using namespace std;
int t, l, s_x, s_y, e_x, e_y;
bool check[301][301];
int cnt;
bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= l || y >= l) return false;
	return true;
}
void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {s_x,s_y},0 });
	check[s_x][s_y] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if (x == e_x && y == e_y) {
			cout << d << '\n';
			return;
		}
		int nx = x - 1; int ny = y - 2;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x - 2; ny = y - 1;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x + 1; ny = y - 2;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x + 2; ny = y - 1;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x - 1; ny = y + 2;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x - 2; ny = y + 1;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x + 1; ny = y + 2;
		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}

		nx = x + 2; ny = y + 1;

		if (!check[nx][ny] && isRange(nx, ny)) {
			q.push({ {nx,ny},d + 1 });
			check[nx][ny] = true;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;

	while (t--) {
		cin >> l;
		cin >> s_x >> s_y;
		cin >> e_x >> e_y;
		bfs();
		memset(check, false, sizeof(check));
	}

	return 0;
}