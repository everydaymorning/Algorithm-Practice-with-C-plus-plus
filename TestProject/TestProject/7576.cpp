#include <bits/stdc++.h>
using namespace std;


int tomato[1002][1002];
int vis[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> q;
	bool found = false;
	bool found2 = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				vis[i][j] = 1;
			}
			else if (tomato[i][j] == 0) {
				found = true;
			}
			else if (tomato[i][j] == -1) vis[i][j] = -1;
		}
	}
	if (found == false) {
		cout << "0" << '\n';
		return 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tomato[nx][ny] == -1) {
				vis[nx][ny] = -1;
				continue;
			}
			if (tomato[nx][ny] != 0 || vis[nx][ny]) {
				continue;
			}
			
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push(make_pair(nx, ny));

			
		}
		
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] > mx) {
				mx = vis[i][j] - 1;
			}
			if (vis[i][j] == 0) {
				found2 = true;
			}
		}
	}
	if (found2 == true) {
		cout << "-1" << '\n';
		return 0;
	}
	
	cout << mx << '\n';



	return 0;
}