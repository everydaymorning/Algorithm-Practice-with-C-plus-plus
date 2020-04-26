#include <bits/stdc++.h>
using namespace std;
char MAP[13][7];
bool check[13][7];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans;
int cnt;
bool flag;
vector<pair<int, int>> v, tmp;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	v.push_back({ a,b });
	check[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (check[nx][ny]) continue;
			if (MAP[x][y] == MAP[nx][ny]) {
				q.push({ nx,ny });
				check[nx][ny] = true;
				v.push_back({ nx,ny });
				cnt++;
			}
		}
	}
	
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> MAP[i][j];
		}
	}
	while (1) {
		flag = false;
		memset(check, false, sizeof(check));
		tmp.clear();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cnt = 1;
				if (MAP[i][j] == '.' || check[i][j]) continue;
				bfs(i, j);

				if (cnt >= 4) {
					flag = true;
					for (int k = 0; k < v.size(); k++) {
						tmp.push_back(v[k]);
					}
				}
				v.clear();

			}
		}

		for (int i = 0; i < tmp.size(); i++) {

			int x = tmp[i].first;
			int y = tmp[i].second;
			MAP[x][y] = '.';
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 11; j > 0; j--) {
				if (MAP[j][i] != '.') continue;
				for (int k = j - 1; k >= 0; k--) {
					if (MAP[k][i] == '.') continue;
					MAP[j][i] = MAP[k][i];
					MAP[k][i] = '.';
					break;
				}
			}
		}
		if (flag) ans++;
		else break;
	}
	cout << ans;
	return 0;
}