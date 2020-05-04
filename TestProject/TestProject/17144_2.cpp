#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int MAP[51][51];
int TEMP[51][51];
int mise_x[2];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void move_up() {
	for (int i = mise_x[0] - 1; i > 0; i--) {
		MAP[i][0] = MAP[i - 1][0];
	}

	for (int j = 0; j < c - 1; j++) {
		MAP[0][j] = MAP[0][j + 1];
	}

	for (int i = 0; i < mise_x[0]; i++) {
		MAP[i][c - 1] = MAP[i + 1][c - 1];
	}

	for (int j = c - 1; j > 1; j--) {
		MAP[mise_x[0]][j] = MAP[mise_x[0]][j - 1];
	}
	MAP[mise_x[0]][1] = 0;
}

void move_down() {
	for (int i = mise_x[1] + 1; i < r - 1; i++) {
		MAP[i][0] = MAP[i + 1][0];
	}

	for (int j = 0; j < c - 1; j++) {
		MAP[r - 1][j] = MAP[r - 1][j + 1];
	}

	for (int i = r - 1; i > mise_x[1]; i--) {
		MAP[i][c - 1] = MAP[i - 1][c - 1];
	}

	for (int j = c - 1; j > 1; j--) {
		MAP[mise_x[1]][j] = MAP[mise_x[1]][j - 1];
	}
	MAP[mise_x[1]][1] = 0;
}
void go(int x, int y) {
	int avg = MAP[x][y] / 5;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (MAP[nx][ny] == -1) continue;
		TEMP[nx][ny] += avg;
		TEMP[x][y] -= avg;
	}
}
void count() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			MAP[i][j] += TEMP[i][j];
		}
	}
}
void setting() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			TEMP[i][j] = 0;
		}
	}
}
void calculate() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (MAP[i][j] > 0) sum += MAP[i][j];
		}
	}
	cout << sum;
}
int main() {
	cin >> r >> c >> t;
	int idx = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				mise_x[idx] = i;
				idx++;
			}
		}
	}
	while (t--) {
		setting();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (MAP[i][j] > 0) {
					go(i, j);
				}
			}
		}
		count();

		move_up();
		move_down();
	}
	calculate();
	return 0;
	

}