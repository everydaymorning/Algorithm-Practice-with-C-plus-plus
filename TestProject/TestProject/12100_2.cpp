#include <bits/stdc++.h>
using namespace std;
int MAP[21][21];
int TEMP[21][21];
int n;
int MAX;
int direction[5];
void findMAX() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MAX = max(MAX, TEMP[i][j]);
		}
	}
}
void moveUp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[j][i] != 0) continue;
			for (int k = j + 1; k < n; k++) {
				if (TEMP[k][i] == 0)continue;
				TEMP[j][i] = TEMP[k][i];
				TEMP[k][i] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[j][i] == 0) continue;
			if (TEMP[j][i] == TEMP[j + 1][i]) {
				TEMP[j][i] += TEMP[j + 1][i];
				TEMP[j + 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[j][i] != 0) continue;
			for (int k = j + 1; k < n; k++) {
				if (TEMP[k][i] == 0)continue;
				TEMP[j][i] = TEMP[k][i];
				TEMP[k][i] = 0;
				break;
			}
		}
	}
}

void moveDown() {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[j][i] != 0) continue;
			for (int k = j - 1; k >= 0; k--) {
				if (TEMP[k][i] == 0) continue;
				TEMP[j][i] = TEMP[k][i];
				TEMP[k][i] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[j][i] == 0) continue;
			if (TEMP[j][i] == TEMP[j - 1][i]) {
				TEMP[j][i] += TEMP[j - 1][i];
				TEMP[j - 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[j][i] != 0) continue;
			for (int k = j - 1; k >= 0; k--) {
				if (TEMP[k][i] == 0) continue;
				TEMP[j][i] = TEMP[k][i];
				TEMP[k][i] = 0;
				break;
			}
		}
	}
}

void moveRight() {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[i][j] != 0) continue;
			for (int k = j - 1; k >= 0; k--) {
				if (TEMP[i][k] == 0) continue;
				TEMP[i][j] = TEMP[i][k];
				TEMP[i][k] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[i][j] == 0) continue;
			if (TEMP[i][j] == TEMP[i][j - 1]) {
				TEMP[i][j] += TEMP[i][j - 1];
				TEMP[i][j - 1] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > 0; j--) {
			if (TEMP[i][j] != 0) continue;
			for (int k = j - 1; k >= 0; k--) {
				if (TEMP[i][k] == 0) continue;
				TEMP[i][j] = TEMP[i][k];
				TEMP[i][k] = 0;
				break;
			}
		}
	}
}

void moveLeft() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[i][j] != 0) continue;
			for (int k = j + 1; k < n; k++) {
				if (TEMP[i][k] == 0)continue;
				TEMP[i][j] = TEMP[i][k];
				TEMP[i][k] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[i][j] == 0) continue;
			if (TEMP[i][j] == TEMP[i][j + 1]) {
				TEMP[i][j] += TEMP[i][j + 1];
				TEMP[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (TEMP[i][j] != 0) continue;
			for (int k = j + 1; k < n; k++) {
				if (TEMP[i][k] == 0)continue;
				TEMP[i][j] = TEMP[i][k];
				TEMP[i][k] = 0;
				break;
			}
		}
	}
}

void go() {
	for (int i = 0; i < 5; i++) {
		int dir = direction[i];
		switch (dir) {
		case 0: moveUp(); break;
		case 1: moveLeft(); break;
		case 2: moveDown(); break;
		case 3: moveRight(); break;
		}
	}
}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void dfs(int cnt) {
	if (cnt >= 5) {
		setting();
		go();
		findMAX();
		return;
	}
	
	for (int dir = 0; dir < 4; dir++) {
		direction[cnt] = dir;
		dfs(cnt + 1);
	}

}
void INPUT() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	INPUT();
	dfs(0);
	cout << MAX;
	return 0;
}