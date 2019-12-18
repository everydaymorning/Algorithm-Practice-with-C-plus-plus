#include <bits/stdc++.h>

using namespace std;
int board[51][51];
bool check[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };// ºÏ, µ¿, ³², ¼­

int main() {
	int n, m;
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			cin >> t;
			board[i][j] = t;
		}
	}
	
	while (1) {
		if (!check[r][c]) {
			check[r][c] = 1;
			cnt++;
		}
		bool back = false;
		
		for (int dir = 0; dir < 4; dir++) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] != 0 || check[nx][ny]) continue;

			r = nx;
			c = ny;
			back = true;
			break;
		}

		if (!back) {
			r = r + dx[(d + 2) % 4];
			c = c + dy[(d + 2) % 4];

			if (r < 0 || r >= n || c < 0 || c >= m || board[r][c]) break;

		}

	}

	printf("%d", cnt);
	return 0;
}