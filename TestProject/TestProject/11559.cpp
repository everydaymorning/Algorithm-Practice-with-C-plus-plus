#include <bits/stdc++.h>
using namespace std;
char MAP[13][7];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[13][7];
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ a,b });
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		char puyo = MAP[x][y];
		cout << "puyo: " << puyo << '\n';
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
			if (check[nx][ny] || MAP[nx][ny] != puyo) continue;
			cout << "MAP[nx][ny]: " << MAP[nx][ny] << '\n';
			q.push({ nx,ny });
			check[nx][ny] = true;
			v.push_back({ nx,ny });
			cnt++;
		}
	}
	memset(check, false, sizeof(check));

	cout << "cnt: " << cnt << '\n';
	if (cnt >= 4) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			bool flag = false;
			for (int j = x-1; j >= 0; j--) {
				if(MAP[j][y] >= 'A' && MAP[j][y] <= 'Z'){
					cout << "j: " << j << " y: " << y << " MAP[j][y]: " << MAP[j][y] << '\n';
					MAP[x][y] = MAP[j][y];
					MAP[j][y] = '.';
				}
				else {
					MAP[x][y] = '.';
					break;
				}
			}
		}
	}
	v.clear();
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (MAP[i][j] == 'R' || MAP[i][j] == 'G' || MAP[i][j] == 'B' || MAP[i][j] == 'P' || MAP[i][j] == 'Y') {
				cout << "MAP: " << MAP[i][j] << '\n';
				bfs(i, j);
				cout << '\n';
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << MAP[i][j];
		}
		cout << '\n';
	}
	return 0;
}