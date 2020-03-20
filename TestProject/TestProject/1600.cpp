#include <bits/stdc++.h>
using namespace std;
int k, w, h;
bool check[201][201][31];
int MAP[201][201];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int knight_x[8] = { -2,-2,-1,-1,1,1,2,2 };
int knight_y[8] = { -1,1,-2,2,-2,2,-1,1 };
void bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,0} });
	check[0][0][0] = true;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second.first;
		int nk = q.front().second.second;
		q.pop();
		if (x == h - 1 && y == w - 1) {
			cout << d;
			return;
		}
		

		if(nk < k){

			for (int dir = 0; dir < 8; dir++) {
				int nx = x + knight_x[dir];
				int ny = y + knight_y[dir];
				//cout << "nx: " << nx << "  ny: " << ny << '\n';

				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (check[nx][ny][nk + 1] || MAP[nx][ny] == 1) continue;
				
				q.push({ {nx,ny},{d + 1,nk + 1} });
				check[nx][ny][nk + 1] = true;
			}

		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (check[nx][ny][nk] || MAP[nx][ny] == 1) continue;
			/*if (nx == h - 1 && ny == w - 1) {
				cout << d + 1;
				return;
			}*/
			q.push({ {nx,ny},{d + 1,nk} });
			check[nx][ny][nk] = true;
		}
	}
	cout << "-1";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> MAP[i][j];
		}
	}

	bfs();
	return 0;
}