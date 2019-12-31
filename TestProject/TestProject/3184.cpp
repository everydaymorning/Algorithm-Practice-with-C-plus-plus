#include <bits/stdc++.h>
using namespace std;
char arr[251][251];
bool check[251][251];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int r, c;
int wolf, sheep;
void Input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = true;
	int w = 0, s = 0;
	if (arr[a][b] == 'v') w++;
	else if (arr[a][b] == 'o') s++;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (check[nx][ny] || arr[nx][ny] == '#') continue;
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (arr[nx][ny] == 'v') w++;
			else if (arr[nx][ny] == 'o') s++;
		}
		
	}
	if (w < s) sheep += s;
	else wolf += w;
}

void Solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (check[i][j] || arr[i][j] == '#') continue;
			bfs(i, j);
		}
	}

	printf("%d %d", sheep, wolf);
}

void Solution() {
	Input();
	Solve();
}
int main() {

	Solution();

	return 0;
}