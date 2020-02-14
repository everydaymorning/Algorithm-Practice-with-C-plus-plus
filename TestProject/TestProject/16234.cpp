#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int a, b;
int MAP[101][101];
bool check[101][101];
bool check2[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int temp;
int res;

bool canMove(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (abs(MAP[x][y] - MAP[nx][ny]) >= L && abs(MAP[x][y] - MAP[nx][ny]) <= R) return true;
	}
	return false;
}
void bfs(int a, int b) {
	queue<pair<int, int>> q1;
	vector<pair<int, int>> v;
	q1.push({ a,b });
	v.push_back({ a,b });
	check[a][b] = true;
	int sum = 0;
	int cnt = 0;
	while (!q1.empty()) {
		int x = q1.front().first;
		int y = q1.front().second;
		int val = MAP[x][y];
		q1.pop();
		sum += val;
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (check[nx][ny]) continue;
			int nval = MAP[nx][ny];
			if (abs(val - nval) >= L && abs(val - nval) <= R) {
				q1.push({ nx,ny });
				v.push_back({ nx,ny });
				check[nx][ny] = true;
			}
		}
	}
	int avg = (int)sum / cnt;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		MAP[x][y] = avg;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	bool flag = true;

	while (1) {
		flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j] && canMove(i, j)) {
					bfs(i, j);
					flag = true;
				}
			}
		}
		if (flag) {
			res++;
		}
		else {
			break;
		}
		memset(check, false, sizeof(check));
	}
	cout << res;
	return 0;
}