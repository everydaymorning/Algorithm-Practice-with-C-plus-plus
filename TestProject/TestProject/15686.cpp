#include <bits/stdc++.h>
using namespace std;
int n, m;
bool check[14];
vector<pair<int, int>> ch, home, v;
int MAP[51][51];
int total_dist;
int res = 2147483647;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void count_distance() {
	for (int i = 0; i < home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		int d = 2147483647;

		for (int j = 0; j < v.size(); j++) {
			int nx = v[j].first;
			int ny = v[j].second;
			int tmp_dist = abs(nx - x) + abs(ny - y);

			d = min(tmp_dist, d);
		}
		total_dist += d;
	}
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		count_distance();
		res = min(total_dist, res);
		total_dist = 0;
		return;
	}

	for (int i = idx; i < ch.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(ch[i]);
		dfs(i, cnt + 1);
		v.pop_back();
		check[i] = false;
	}

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				ch.push_back({ i,j });
			}
			if (MAP[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << res;
	return 0;

}