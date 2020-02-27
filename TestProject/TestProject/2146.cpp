#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[101][101];
bool check[101][101];
int DIST[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int num = 1;
int MIN = 2147483647;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = true;
	MAP[a][b] = num;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (MAP[nx][ny] == 0 || check[nx][ny]) continue;
			MAP[nx][ny] = num;
			q.push({ nx,ny });
			check[nx][ny] = true;
		}
	}
}

void countBridge(int a, int b, int nation) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	check[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		//cout << "x: " << x << "  y: " << y << '\n';
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (MAP[nx][ny] == nation || check[nx][ny]) continue;
			if (MAP[nx][ny] > 0 && MAP[nx][ny] != nation) {
				MIN = min(MIN, dist);
				//cout << "MIN: " << MIN << '\n';
				return;
			}
			DIST[nx][ny] = DIST[x][y] + 1;
			check[nx][ny] = true;
			q.push({ {nx,ny},dist + 1 });
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] != 0 && !check[i][j]) {
				bfs(i, j);
				num++;
			}
		}
	}
	memset(check, false, sizeof(check));
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (MAP[i][j] != 0 && !check[i][j]) {
				int tmp = MAP[i][j];
				countBridge(i, j, tmp);
				memset(DIST, 0, sizeof(DIST));
				memset(check, false, sizeof(check));
			}
		}
	}
	cout << MIN;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << DIST[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/
	return 0;
}