#include <bits/stdc++.h>
using namespace std;
int r, c, k;
int MAP[102][102];
int TEMP[102][102];
int sum[102];
vector<pair<int, int>> v;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> MAP[i][j];
		}
	}
	
	int cnt = 0;
	int row = 3;
	int col = 3;
	while (1) {
		if (cnt > 100) break;
		if (MAP[r][c] == k) break;
		cnt++;

		if (row >= col) {
			int len = 0;
			for (int i = 1; i <= max(row, col); i++) {
				for (int j = 1; j <= max(row, col); j++) {
					if (MAP[i][j] == 0) continue;
					sum[MAP[i][j]]++;
				}
				for (int j = 1; j <= 101; j++) {
					if (sum[j] == 0) continue;
					v.push_back({ j,sum[j] });
				}
				sort(v.begin(), v.end(), cmp);
				for (int j = 1; j <= 101; j++) {
					MAP[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					int a = v[j].first;
					int b = v[j].second;
					MAP[i][idx] = a;
					MAP[i][idx + 1] = b;
					idx += 2;
				}
				len = max(len, idx - 1);
				v.clear();
				for (int j = 1; j <= 101; j++) {
					sum[j] = 0;
				}
			}
			col = len;
		}
		else {
			int len = 0;
			for (int i = 1; i <= max(row,col); i++) {
				for (int j = 1; j <= max(row,col); j++) {
					TEMP[i][j] = MAP[j][i];
				}
			}

			int max_size = 0;
			for (int i = 1; i <= max(row, col); i++) {
				for (int j = 1; j <= max(row, col); j++) {
					if (TEMP[i][j] == 0) continue;
					sum[TEMP[i][j]]++;
				}
				for (int j = 1; j <= 101; j++) {
					if (sum[j] == 0) continue;
					v.push_back({ j,sum[j] });
				}
				sort(v.begin(), v.end(), cmp);

				for (int j = 1; j <= 101; j++) {
					TEMP[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					int a = v[j].first;
					int b = v[j].second;
					TEMP[i][idx] = a;
					TEMP[i][idx + 1] = b;
					idx += 2;
				}
				len = max(len, idx - 1);
				v.clear();
				for (int j = 1; j <= 101; j++) {
					sum[j] = 0;
				}
			}
			row = len;

			for (int i = 1; i <= max(row, col); i++) {
				for (int j = 1; j <= max(row, col); j++) {
					MAP[j][i] = TEMP[i][j];
				}
			}
		}
		
	}
	if (cnt > 100) cout << "-1";
	else cout << cnt;
	return 0;
}