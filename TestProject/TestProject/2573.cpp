#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[301][301];
int TEMP[301][301];
bool check[301][301];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void copy(int MAP1[301][301], int MAP2[301][301]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			MAP1[i][j] = MAP2[i][j];
		}
	}
}

void bfs(int a, int b) {
	copy(TEMP, MAP);
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (check[nx][ny]) continue;
			if (MAP[nx][ny] == 0) {
				if(TEMP[x][y] > 0) TEMP[x][y] -= 1;

			}
			else if (MAP[nx][ny] != 0) {
				q.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
	copy(MAP, TEMP);

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	int year = 0;
	while (1) {
		int cnt = 0;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (MAP[i][j] != 0 && !check[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << year;
			break;
		}
		else if (cnt == 0) {
			cout << cnt;
			break;
		}
		else {
			year++;
			continue;
		}
	}
	return 0;
}