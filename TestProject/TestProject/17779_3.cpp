#include <bits/stdc++.h>
using namespace std;
int n;
int MAP[21][21];
int TEMP[21][21];
vector<pair<int, int>> point;
int sum[6];
int ans = 2147483647;
bool check(int x, int y, int d1, int d2) {
	if (x + d1 >= n || y + d2 >= n) return false;
	if (x + d1 >= n || y - d2 < 0) return false;
	if (x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
	if (x + d2 + d1 >= n || y + d2 - d1 < 0) return false;
	return true;
}

void go() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TEMP[i][j] = 5;
		}
	}
	int cnt = 0;

	for (int i = 0; i < point[1].first; i++) {
		if (i >= point[0].first) cnt++;
		for (int j = 0; j <= point[0].second - cnt; j++) {
			TEMP[i][j] = 1;
		}
	}

	cnt = 0;
	for (int i = 0; i <= point[2].first; i++) {
		if (i > point[0].first) cnt++;
		for (int j = point[0].second + 1 + cnt; j < n; j++) {
			TEMP[i][j] = 2;
		}
	}

	cnt = 0;

	for (int i = n - 1; i >= point[1].first; i--) {
		if (i < point[3].first) cnt++;
		for (int j = 0; j < point[3].second - cnt; j++) {
			TEMP[i][j] = 3;
		}
	}
	
	cnt = 0;
	for (int i = n - 1; i > point[2].first; i--) {
		if (i <= point[3].first) cnt++;
		for (int j = point[3].second + cnt; j < n; j++) {
			TEMP[i][j] = 4;
		}
	}

}

void cal() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[TEMP[i][j]] += MAP[i][j];
		}
	}
	sort(sum, sum + 6);

	int tmp = sum[5] - sum[1];
	for (int i = 0; i < 6; i++) {
		sum[i] = 0;
	}
	ans = min(tmp, ans);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d1 = 1; d1 < j; d1++) {
				for (int d2 = 1; d2 <= n - j; d2++) {
					if (check(i, j, d1, d2)) {
						point.push_back({ i,j });
						point.push_back({ i + d1, j - d1 });
						point.push_back({ i + d2, j + d2 });
						point.push_back({ i + d1 + d2, j - d1 + d2 });

						go();
						cal();
						point.clear();
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}