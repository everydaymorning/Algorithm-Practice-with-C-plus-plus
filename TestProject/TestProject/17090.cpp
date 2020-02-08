#include <bits/stdc++.h>
using namespace std;
char MAP[501][501];
int check[501][501];
int n, m;

int dfs(int x, int y) {
	
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return 1;
	}
	char tmp = MAP[x][y];

	int& res = check[x][y];
	if (res != -1) return res;
	res = 0;
	if (tmp == 'U') {
		res = dfs(x - 1, y);
		cout << "x: " << x << "  y: " << y << "  res: " << res << '\n';
		return res;
	}
	else if (tmp == 'D') {
		res = dfs(x + 1, y);
		cout << "x: " << x << "  y: " << y << "  res: " << res << '\n';
		return res;
	}
	else if (tmp == 'L') {
		res = dfs(x, y - 1);
		cout << "x: " << x << "  y: " << y << "  res: " << res << '\n';
		return res;
	}
	else {
		res = dfs(x, y + 1);
		cout << "x: " << x << "  y: " << y << "  res: " << res << '\n';
		return res;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
		}
	}
	memset(check, -1, sizeof(check));

	int res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res += dfs(i, j);
		}
	}

	cout << res;
	return 0;

}