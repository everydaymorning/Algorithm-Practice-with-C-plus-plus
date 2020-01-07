#include <bits/stdc++.h>
using namespace std;

char MAP[60][60];
char chess[8][8];

void input(int x, int y) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chess[i][j] = MAP[x + i][y + j];
		}
	}
}

int solve() {

	int BW = 0;
	int WB = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && chess[i][j] == 'W') {
				BW++;
			}
			if ((i + j) % 2 == 1 && chess[i][j] == 'B') {
				BW++;
			}
			if ((i + j) % 2 == 0 && chess[i][j] == 'B') {
				WB++;
			}
			if ((i + j) % 2 == 1 && chess[i][j] == 'W') {
				WB++;
			}
		}
	}

	return min(WB, BW);
}


int main() {
	
	int n, m;
	cin >> n >> m;
	int MN = 99999999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			input(i, j);
			MN = min(MN, solve());
		}
	}

	printf("%d", MN);

	return 0;
}