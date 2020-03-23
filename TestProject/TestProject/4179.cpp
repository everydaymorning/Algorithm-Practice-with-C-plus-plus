#include <bits/stdc++.h>
using namespace std;
char MAP[1001][1001];
bool check[1001][1001];
bool check_j[1001][1001];
int r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
queue<pair<int, int>> f;
int cnt;
void bfs() {
	while (!q.empty()) {

		int q_size = q.size();
		int f_size = f.size();
		cnt++;

		while (f_size--) {
			int x = f.front().first;
			int y = f.front().second;
			f.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
					if (MAP[nx][ny] != '#' && !check[nx][ny]) {
						f.push({ nx,ny });
						MAP[nx][ny] = 'F';
						check[nx][ny] = true;
					}
				}
			}
		}

		while (q_size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
					if (MAP[nx][ny] == '.' && !check_j[nx][ny]) {
						q.push({nx,ny});
						check_j[nx][ny] = true;
					}
				}
				else {
					cout << cnt;
					return;
				}
			}
		}

		
	}
	cout << "IMPOSSIBLE";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> MAP[i][j];

			if (MAP[i][j] == 'J') {
				q.push({i,j});
			}

			else if (MAP[i][j] == 'F') {
				f.push({ i,j });
			}
		}
	}

	bfs();
	return 0;
}