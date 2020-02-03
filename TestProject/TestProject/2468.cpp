#include <bits/stdc++.h>
using namespace std;

int safe[101][101];
bool check[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int mx;
int n;
int res;
int area;
void bfs(int a, int b, int c) {
	if (check[a][b] || safe[a][b] <= c) return;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = true;
	area++;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (safe[nx][ny] > c && !check[nx][ny]) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> safe[i][j];
			mx = max(mx, safe[i][j]);
		}
	}

	for (int i = 1; i <= mx; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				bfs(j, k, i);
			}
		}
		res = max(res, area);
		area = 0;
		memset(check, false, sizeof(check));
	}
	if (res == 0) {
		cout << "1";
	}
	else {
		cout << res;
	}
	return 0;
}