#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[51][51];
vector<pair<int, int>> ch, home, tmp;
int MIN = 2147483647;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[14];
void calculate() {
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		int tmp_min = 2147483647;
		for (int j = 0; j < tmp.size(); j++) {
			int nx = tmp[j].first;
			int ny = tmp[j].second;
			int dist = abs(x - nx) + abs(y - ny);
			tmp_min = min(tmp_min, dist);
		}
		sum += tmp_min;
	}
	MIN = min(MIN, sum);
}
void dfs(int cnt, int idx) {
	if (cnt == m) {
		calculate();
		return;
	}

	for (int i = idx; i < ch.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		tmp.push_back(ch[i]);
		dfs(cnt + 1, i);
		tmp.pop_back();
		visit[i] = false;
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
			else if (MAP[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	dfs(0,0);
	cout << MIN;
	return 0;

}