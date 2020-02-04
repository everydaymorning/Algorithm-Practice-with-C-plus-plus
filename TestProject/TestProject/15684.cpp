#include <bits/stdc++.h>
using namespace std;

int arr[31][11];
int n, m, h;
int ans = 4;
bool check() {
	for (int i = 0; i < n; i++) {
		int tmp = i;

		for (int j = 0; j < h; j++) {
			if (arr[j][tmp] == 1) {
				tmp++;
			}
			else if (tmp > 0 && arr[j][tmp - 1] == 1) {
				tmp--;
			}
		}
		if (tmp != i) {
			return false;
		}
	}
	return true;
}

void dfs(int x, int y, int cnt) {
	if (ans <= cnt) return;
	else if (check()) {
		ans = min(ans, cnt);
		return;
	}
	else if (cnt == 3) {
		return;
	}

	for (int i = x; i < h; i++) {
		int k = 0;
		if (i == x) k = y;

		for (int j = k; j < n - 1; j++) {
			if (arr[i][j - 1] == 1 || arr[i][j + 1] == 1 || arr[i][j] == 1) continue; // 가로선은 접할 수 없는 조건
			arr[i][j] = 1;
			dfs(i, j + 2, cnt + 1);
			arr[i][j] = 0;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
	}

	dfs(0, 0, 0);
	if (ans > 3) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
	return 0;
}