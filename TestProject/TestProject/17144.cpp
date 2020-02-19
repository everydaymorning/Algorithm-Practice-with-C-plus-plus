#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int MAP[51][51];
int MISE[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> v;
int cnt;
void copy(int MAP1[51][51], int MAP2[51][51]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			MAP1[i][j] = MAP2[i][j];
		}
	}
}
void bfs() {
	copy(MISE, MAP);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (MAP[i][j] > 0) {
				int val = MAP[i][j];
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c || MAP[nx][ny] == -1) continue;
					int nval = (int)val / 5;
					MISE[nx][ny] += nval;
					MISE[i][j] -= nval;
				}
			}
		}
	}
	copy(MAP, MISE);
}
void move1() {

	int x = v[0];
	for (int i = x - 1; i > 0; i--) { // 공기청정기 열
		MAP[i][0] = MAP[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) { // 가장 윗줄
		MAP[0][i] = MAP[0][i + 1];
	}
	
	for (int i = 1; i <= x; i++) { // 반대편 열
		MAP[i - 1][c - 1] = MAP[i][c - 1];
	}
	for (int i = c - 1; i > 1; i--) { // 공기청정기 행
		MAP[x][i] = MAP[x][i - 1];
	}
	MAP[x][1] = 0;
}

void move2() {

	int x = v[1];
	for (int i = x + 1; i < r - 1; i++) { // 공기청정기 열
		MAP[i][0] = MAP[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) { 
		MAP[r - 1][i] = MAP[r - 1][i + 1]; //가장 아랫줄
	}
	for (int i = r - 1; i >= x; i--) {
		MAP[i][c - 1] = MAP[i - 1][c - 1]; // 반대편 열
	}
	for (int i = c - 1; i > 1; i--) { //공기청정기 행 
		MAP[x][i] = MAP[x][i - 1];
	}
	MAP[x][1] = 0;
}
void countMISE() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(MAP[i][j] > 0) cnt += MAP[i][j];
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> MAP[i][j];
			
			if (MAP[i][j] == -1) {
				v.push_back(i);
			}
		}
	}
	while (t--) {
		bfs();
		move1();
		move2();
	}
	countMISE();
	cout << cnt;
	return 0;
}