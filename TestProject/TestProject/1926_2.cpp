#include <bits/stdc++.h>
using namespace std;

int paint[501][501];
bool check[501][501];
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paint[i][j];
		}
	}

	queue<pair<int, int>> q;
	
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] || paint[i][j] == 0) continue;
			cnt++;
			
			check[i][j] = true;
			q.push(make_pair(i, j));
			int tmp = 0;
			while (!q.empty()) {
				tmp++;
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (check[nx][ny] || paint[nx][ny] == 0) continue;
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				
			}
			mx = max(mx, tmp);
			
		}
	}

	printf("%d\n", cnt);
	printf("%d", mx);
	return 0;
}