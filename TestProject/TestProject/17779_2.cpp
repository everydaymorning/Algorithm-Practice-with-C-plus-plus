#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[21][21];
int TEMP[21][21];
vector<pair<int, int>> v;
int SUM[6];
int MIN = 2147483647;
bool check(int x, int y, int d1, int d2) {
	if (x + d1 >= n || y - d1 < 0) return false;
	else if (x + d2 >= n || y + d2 >= n) return false;
	else if (x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
	else if (x + d2 + d1 >= n || y + d2 - d1 < 0) return false;
	return true;
}
void calculate() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			SUM[TEMP[i][j]] += MAP[i][j];
		}
	}
	sort(SUM, SUM + 6);
	sum = SUM[5] - SUM[1];
	MIN = min(MIN, sum);
	fill(SUM, SUM + 6, 0);
}
void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TEMP[i][j] = 5;
		}
	}
}
void go() {
	setting();
	int cnt = 0;
	for (int i = 0; i < v[1].first; i++) {
		if (i >= v[0].first) cnt++;
		for (int j = 0; j <= v[0].second - cnt; j++) {
			TEMP[i][j] = 1;
		}
	}
	cnt = 0;
	for (int i = 0; i <= v[2].first; i++) {
		if (i > v[0].first) cnt++;
		for (int j = v[0].second + 1 + cnt; j < n; j++) {
			TEMP[i][j] = 2;
		}
	}
	cnt = 0;
	for (int i = n - 1; i >= v[1].first; i--) {
		if (i < v[3].first) cnt++;
		for (int j = 0; j < v[3].second - cnt; j++) {
			TEMP[i][j] = 3;
		}
	}
	cnt = 0;
	for (int i = n - 1; i > v[2].first; i--) {
		if (i <= v[3].first) cnt++;
		for (int j = v[3].second + cnt; j < n; j++) {
			TEMP[i][j] = 4;
		}
	}
	v.clear();
}
void INPUT() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d1 = 1; d1 <= j; d1++) {
				for (int d2 = 1; d2 < n - j; d2++) {
					if (check(i, j, d1, d2)) {
						v.push_back({ i,j });
						v.push_back({ i + d1, j - d1 });
						v.push_back({ i + d2, j + d2 });
						v.push_back({ i + d1 + d2, j - d1 + d2 });
						go();
						calculate();
					}
				}
			}
		}
	}
	cout << MIN;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	INPUT();
	solve();
	return 0;
}