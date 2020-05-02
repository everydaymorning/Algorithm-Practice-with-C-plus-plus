#include <bits/stdc++.h>
using namespace std;
int MAP[51][51];
bool check[51][51];
int N, L, R;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans;

bool move(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (abs(MAP[x][y] - MAP[nx][ny]) >= L && abs(MAP[x][y] - MAP[nx][ny]) <= R) return true;
	}
	return false;
}
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>>v;
	q.push({ x,y });
	check[x][y] = true;
	v.push_back({ x,y });
	int sum = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sum += MAP[x][y];
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (check[nx][ny]) continue;
			if (abs(MAP[x][y] - MAP[nx][ny]) >= L && abs(MAP[x][y] - MAP[nx][ny]) <= R) {
				q.push({ nx,ny });
				check[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}
	int avg = (int)sum / cnt;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		MAP[x][y] = avg;
	}
	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << '\n';
	}*/
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
	while (1) {
		memset(check, false, sizeof(check));
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j]) continue;
				if (move(i, j)) {
					bfs(i, j);
					flag = true;
				}
			}
		}
		if (flag) ans++;
		else break;

	}
	cout << ans;
	return 0;

}