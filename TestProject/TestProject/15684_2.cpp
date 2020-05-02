#include <bits/stdc++.h>
using namespace std;
int MAP[31][11];
int n, m, h;
int ans = 4;
bool go_sadari() {
	for (int i = 0; i < n; i++) {
		int cur_num = i;

		for (int j = 0; j < h; j++) {
			if (MAP[j][cur_num] == 1) {
				cur_num++;
			}
			else if(cur_num > 0 && MAP[j][cur_num - 1] == 1){
				cur_num--;
			}
		}
		if (i != cur_num) {
			return false;
		}
	}
	return true;
}
void dfs(int cnt, int idx) {
	if (cnt >= ans) return;
	if (go_sadari()) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = idx; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (MAP[i][j] == 1 || MAP[i][j + 1] == 1 || (MAP[i][j - 1] == 1 && j > 0)) continue;
			MAP[i][j] = 1;
			dfs(cnt + 1, i);
			MAP[i][j] = 0;
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
		MAP[a - 1][b - 1] = 1;
	}

	dfs(0, 0);
	if (ans >= 4) cout << "-1";
	else cout << ans;
	return 0;
}