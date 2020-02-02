#include <bits/stdc++.h>
using namespace std;

char arr[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	bool possible = false;
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'W') {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (arr[nx][ny] == 'S') {
						possible = true;
						break;
					}
				}
			}
		}
	}
	if (possible) {
		cout << "0";
		return 0;
	}
	else {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 'S' || arr[i][j] == 'W') continue;
				arr[i][j] = 'D';
			}
		}
	}
	cout << "1" << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}