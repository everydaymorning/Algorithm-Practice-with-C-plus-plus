#include <bits/stdc++.h>
using namespace std;
char MAP[51][51];
bool check[51][51];
bool check1[51][51];
int r, c;
int dist[51][51];
int s_x, s_y, w_x, w_y, d_x, d_y;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> go;
queue<pair<int, int>> water;
void bfs() {

	while (!go.empty()) {
		int go_size = go.size();
		int water_size = water.size();
		while (water_size--) {

			int water_x = water.front().first;
			int water_y = water.front().second;
			water.pop();
			check1[water_x][water_y] = true;
			for (int dir = 0; dir < 4; dir++) {
				int wnx = water_x + dx[dir];
				int wny = water_y + dy[dir];
				if (wnx < 0 || wny < 0 || wnx >= r || wny >= c) continue;
				if (check[wnx][wny] || MAP[wnx][wny] == 'D' || MAP[wnx][wny] == 'X') continue;
				check[wnx][wny] = true;
				MAP[wnx][wny] = '*';
				water.push({ wnx,wny });
			}
		}
		
		while (go_size--) {
			int go_x = go.front().first;
			int go_y = go.front().second;
			go.pop();
			check[go_x][go_y] = true;
			if (go_x == d_x && go_y == d_y) {
				cout << dist[go_x][go_y];
				return;
			}
			for (int dir = 0; dir < 4; dir++) {
				int gnx = go_x + dx[dir];
				int gny = go_y + dy[dir];
				if (gnx < 0 || gny < 0 || gnx >= r || gny >= c) continue;
				if (check1[gnx][gny] || MAP[gnx][gny] == '*' || MAP[gnx][gny] == 'X') continue;
				check1[gnx][gny] = true;
				MAP[gnx][gny] = 'S';
				dist[gnx][gny] = dist[go_x][go_y] + 1;
				go.push({ gnx,gny });
			}
		}
		
	}
	cout << "KAKTUS";
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'S') {
				go.push({ i,j });
			}
			if (MAP[i][j] == '*') {
				water.push({ i,j });
			}
			if (MAP[i][j] == 'D') {
				d_x = i;
				d_y = j;
			}
		}
	}
	bfs();
	return 0;

}