#include <bits/stdc++.h>
using namespace std;
int MAP[101][101];
bool check[101][101];
char paper[51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
int start_x, start_y, end_x, end_y;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> paper[i];
	}
	int d = 0; // ³²ÂÊ
	int x = 50;
	int y = 50;
	MAP[x][y] = 1;

	for (int i = 0; i < n; i++) {
		if (paper[i] == 'R') {
			d = (d + 1) % 4;
		}
		else if (paper[i] == 'L') {
			d = (d + 3) % 4;
		}
		else if (paper[i] == 'F') {
			x = x + dx[d];
			y = y + dy[d];
			MAP[x][y] = 1;
		}
	}
	start_x = 101;
	start_y = 101;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (MAP[i][j] == 1) {
				start_x = min(i, start_x);
				start_y = min(j, start_y);
				end_x = max(i, end_x);
				end_y = max(j, end_y);
			}
		}
	}

	for (int i = start_x; i <= end_x; i++) {
		for (int j = start_y; j <= end_y; j++) {
			if (MAP[i][j] == 1) cout << '.';
			else cout << '#';
		}
		cout << '\n';
	}
}