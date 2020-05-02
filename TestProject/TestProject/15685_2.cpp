#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[101][101];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<int> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		v.clear();
		MAP[x][y] = 1;
		v.push_back(d);
		x = x + dx[d];
		y = y + dy[d];
		MAP[x][y] = 1;
		for (int j = 0; j < g; j++) {
			int cnt = v.size();
			for (int k = cnt - 1; k >= 0; k--) {
				int nd = (v[k] + 1) % 4;
				x = x + dx[nd];
				y = y + dy[nd];
				MAP[x][y] = 1;
				v.push_back(nd);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (MAP[i][j] == 1 && MAP[i][j + 1] == 1 && MAP[i + 1][j] == 1 && MAP[i + 1][j + 1] == 1) ans++;
		}
	}
	cout << ans;
	return 0;
}