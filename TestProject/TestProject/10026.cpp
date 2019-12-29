#include <bits/stdc++.h>
using namespace std;

char rgb[105][105];
bool check[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;

void bfs(int a, int b) {

	queue<pair<int, int>> q;
	check[a][b] = true;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny] || rgb[nx][ny] != rgb[a][b]) continue;

			check[nx][ny] = true;
			q.push(make_pair(nx, ny));

		}
	}
	
}

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> rgb[i][j];
		}
	}
}

void Solution() {
	int answer, answer2;
	answer = answer2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) continue;
			bfs(i, j);
			answer++;
		}
	}

	memset(check, false, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rgb[i][j] == 'G') rgb[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) continue;
			bfs(i, j);
			answer2++;
		}
	}

	cout << answer << " " << answer2;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Solve();

	return 0;
}