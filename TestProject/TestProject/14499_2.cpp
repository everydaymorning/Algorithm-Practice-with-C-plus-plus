#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k;

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int DICE[7];
int MAP[21][21];
int arr[1001];
int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	

	for (int i = 0; i < k; i++) {
		int d1 = DICE[1];
		int d2 = DICE[2];
		int d3 = DICE[3];
		int d4 = DICE[4];
		int d5 = DICE[5];
		int d6 = DICE[6];
		int dir = arr[i];
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		if (dir == 1) {
			DICE[1] = d4;
			DICE[3] = d1;
			DICE[4] = d6;
			DICE[6] = d3;
		}
		else if (dir == 2) {
			DICE[1] = d3;
			DICE[3] = d6;
			DICE[4] = d1;
			DICE[6] = d4;
		}
		else if (dir == 3) {
			DICE[1] = d5;
			DICE[2] = d1;
			DICE[5] = d6;
			DICE[6] = d2;
		}
		else if (dir == 4) {
			DICE[1] = d2;
			DICE[2] = d6;
			DICE[5] = d1;
			DICE[6] = d5;
		}

		if (MAP[nx][ny] != 0) {
			DICE[6] = MAP[nx][ny];
			MAP[nx][ny] = 0;
		}
		else {
			MAP[nx][ny] = DICE[6];
		}

		cout << DICE[1] << '\n';
		x = nx;
		y = ny;
	}
	return 0;
}