#include <bits/stdc++.h>
using namespace std;
string MAP[21];
bool check[26];
int alpha[26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
int cnt;
void dfs(int a, int b, int tmp) {
	cnt = max(cnt, tmp);
	for (int dir = 0; dir < 4; dir++) {
		int nx = a + dx[dir];
		int ny = b + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (check[MAP[nx][ny] - 'A']) continue;
		check[MAP[nx][ny] - 'A'] = true;
		dfs(nx, ny, tmp + 1);
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

	cout << cnt;
	return 0;
}