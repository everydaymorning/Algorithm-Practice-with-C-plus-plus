#include <bits/stdc++.h>
using namespace std;
int n, m;
int MAP[9][9];
int TEMP[9][9];
int MIN = 2147483647;
vector<pair<pair<int, int>, pair<int, int>>> v;
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			TEMP[i][j] = MAP[i][j];
		}
	}
}
void cctv_right(int x, int y) {
	for (int j = y + 1; j < m; j++) {
		if (TEMP[x][j] == 6) break;
		if (TEMP[x][j] >= 1 && TEMP[x][j] <= 5) continue;
		TEMP[x][j] = 9;
	}
}

void cctv_left(int x, int y) {
	for (int j = y - 1; j >= 0; j--) {
		if (TEMP[x][j] == 6) break;
		if (TEMP[x][j] >= 1 && TEMP[x][j] <= 5) continue;
		TEMP[x][j] = 9;
	}
}

void cctv_up(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (TEMP[i][y] == 6) break;
		if (TEMP[i][y] >= 1 && TEMP[i][y] <= 5) continue;
		TEMP[i][y] = 9;
	}
}

void cctv_down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (TEMP[i][y] == 6) break;
		if (TEMP[i][y] >= 1 && TEMP[i][y] <= 5) continue;
		TEMP[i][y] = 9;
	}
}
void cctv() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second.first == 1) {
			if (v[i].second.second == 0) cctv_right(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 1) cctv_left(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 2) cctv_up(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 3) cctv_down(v[i].first.first, v[i].first.second);
		}
		else if (v[i].second.first == 2) {
			if (v[i].second.second == 0 || v[i].second.second == 1) {
				cctv_right(v[i].first.first, v[i].first.second);
				cctv_left(v[i].first.first, v[i].first.second);
			}
			else if(v[i].second.second == 3 || v[i].second.second == 4){
				cctv_up(v[i].first.first, v[i].first.second);
				cctv_down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3) {
			if (v[i].second.second == 0) {
				cctv_right(v[i].first.first, v[i].first.second);
				cctv_down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1) {
				cctv_down(v[i].first.first, v[i].first.second);
				cctv_left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2) {
				cctv_left(v[i].first.first, v[i].first.second);
				cctv_up(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3) {
				cctv_up(v[i].first.first, v[i].first.second);
				cctv_right(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4) {
			if (v[i].second.second == 0) {
				cctv_right(v[i].first.first, v[i].first.second);
				cctv_down(v[i].first.first, v[i].first.second);
				cctv_left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1) {
				cctv_down(v[i].first.first, v[i].first.second);
				cctv_left(v[i].first.first, v[i].first.second);
				cctv_up(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2) {
				cctv_left(v[i].first.first, v[i].first.second);
				cctv_up(v[i].first.first, v[i].first.second);
				cctv_right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3) {
				cctv_up(v[i].first.first, v[i].first.second);
				cctv_right(v[i].first.first, v[i].first.second);
				cctv_down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 5) {
			cctv_right(v[i].first.first, v[i].first.second);
			cctv_down(v[i].first.first, v[i].first.second);
			cctv_left(v[i].first.first, v[i].first.second);
			cctv_up(v[i].first.first, v[i].first.second);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (TEMP[i][j] == 0) res++;
		}
	}
	MIN = min(res, MIN);
}
void dfs(int cnt) {
	if (cnt == v.size()) {
		copy();
		cctv();
		return;
	}

	v[cnt].second.second = 0;
	dfs(cnt + 1);

	v[cnt].second.second = 1;
	dfs(cnt + 1);

	v[cnt].second.second = 2;
	dfs(cnt + 1);

	v[cnt].second.second = 3;
	dfs(cnt + 1);

}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] >= 1 && MAP[i][j] <= 5) {
				v.push_back({ {i,j},{MAP[i][j], -1} });
			}
		}
	}

	dfs(0);
	cout << MIN;
	return 0;

}