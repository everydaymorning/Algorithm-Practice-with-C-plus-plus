#include <bits/stdc++.h>
using namespace std;
int dis[11][11];
bool check[11];
int n;
int res = 987654321;
int start;
void dfs(int idx, int cost, int cnt) {
	if (cnt == n - 1) {
		if (dis[idx][start] != 0) {
			res = min(res, cost + dis[idx][start]);
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (dis[idx][i] != 0 && !check[i]) {
			check[i] = true;
			dfs(i, cost + dis[idx][i], cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dis[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		start = i;
		check[i] = true;
		dfs(i,0,0);
		check[i] = false;
	}
	cout << res;
	return 0;
}