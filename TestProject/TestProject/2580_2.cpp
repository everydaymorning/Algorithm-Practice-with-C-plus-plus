#include <bits/stdc++.h>
using namespace std;
int MAP[10][10];
bool ROW[10][10];
bool COL[10][10];
bool SQ[10][10];

void dfs(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << MAP[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = cnt / 9;
	int y = cnt % 9;
	if (MAP[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (ROW[x][i] == false && COL[y][i] == false && SQ[(x / 3) * 3 + (y / 3)][i] == false) {
				ROW[x][i] = true;
				COL[y][i] = true;
				SQ[(x / 3) * 3 + (y / 3)][i] = true;
				MAP[x][y] = i;
				dfs(cnt + 1);
				MAP[x][y] = 0;
				ROW[x][i] = false;
				COL[y][i] = false;
				SQ[(x / 3) * 3 + (y / 3)][i] = false;
			}
		}
	}
	else dfs(cnt + 1);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] != 0) {
				ROW[i][MAP[i][j]] = true;
				COL[j][MAP[i][j]] = true;
				SQ[(i / 3) * 3 + (j / 3)][MAP[i][j]] = true;
			}
		}
	}

	dfs(0);

	return 0;
}