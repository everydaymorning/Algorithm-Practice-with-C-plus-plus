#include <bits/stdc++.h>
using namespace std;
int MAP[21][21];
int TEMP[21][21];
vector<pair<int, int>> v;
int SUM[6];
int n;
int ans = 2147483647;

void setting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			TEMP[i][j] = 5;
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			SUM[TEMP[i][j]] += MAP[i][j];
		}
	}
	sort(SUM, SUM + 6);
	
	int tmp = SUM[5] - SUM[1];
	//cout << "sum[5]: " << SUM[5] << "  sum[1]: " << SUM[1] << '\n';
	ans = min(ans, tmp);
}
void go() {
	setting();

	int k = 0;
	for (int i = 0; i < v[1].first; i++) {
		if (i >= v[0].first) k++;
		for (int j = 0; j <= v[0].second - k; j++) {
			TEMP[i][j] = 1;
		}
	}
	k = 0;

	for (int i = 0; i <= v[2].first; i++) {
		if (i > v[0].first) k++;
		for (int j = v[0].second + 1 + k; j < n; j++) {
			TEMP[i][j] = 2;
		}
	}
	k = 0;

	for (int i = n - 1; i >= v[1].first; i--) {
		if (i < v[3].first) k++;
		for (int j = 0; j < v[3].second - k; j++) {
			TEMP[i][j] = 3;
		}
	}
	k = 0;
	for (int i = n - 1; i > v[2].first; i--) {
		if (i <= v[3].first) k++;
		for (int j = v[3].second + k; j < n; j++) {
			TEMP[i][j] = 4;
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << TEMP[i][j] << " ";
		}
		cout << '\n';
	}*/
	solve();
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
			for (int d1 = 1; d1 <= j; d1++) {
				for (int d2 = 1; d2 < n - j; d2++) {
					if (i + d1 >= n || j - d1 < 0) continue;
					else if (i + d2 >= n || j + d2 < 0) continue;
					else if (i + d1 + d2 >= n || j - d1 + d2 < 0) continue;
					else if (i + d2 + d1 >= n || j + d2 - d1 < 0) continue;
					v.push_back({ i,j });
					v.push_back({ i + d1, j - d1 });
					v.push_back({ i + d2, j + d2 });
					v.push_back({ i + d2 + d1, j - d1 + d2 });

					go();

					
					fill(SUM, SUM + 6, 0);
					v.clear();
				}
			}
		}
	}
	cout << ans;
	return 0;
}