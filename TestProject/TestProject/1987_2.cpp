#include <bits/stdc++.h>
using namespace std;
int r, c;
string MAP[21];
bool check[27];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int MAX;
void dfs(int x, int y, int cnt) {
	MAX = max(cnt, MAX);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (check[MAP[nx][ny] - 'A']) continue;
		check[MAP[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		check[MAP[nx][ny] - 'A'] = false;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> MAP[i];
	}
	check[MAP[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << MAX;
	return 0;

}