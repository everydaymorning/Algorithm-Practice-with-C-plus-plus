#include <bits/stdc++.h>
using namespace std;
int r, c, k, mx_r, mx_c;
int MAP[101][101];
int arrCount[101];
int cnt;
vector<pair<int, int>> v;

bool cmp_v(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
bool check() {
	int tmp = 0;
	for (int i = 1; i <= 100; i++) {
		int len_c = 0;
		for (int j = 1; j <= 100; j++) {
			if (MAP[i][j] != 0) len_c++;
		}
		tmp = max(tmp, len_c);
	}
	mx_c = tmp;

	tmp = 0;
	for (int i = 1; i <= 100; i++) {
		int len_r = 0;
		for (int j = 1; j <= 100; j++) {
			if (MAP[j][i] != 0) len_r++;
		}
		tmp = max(tmp, len_r);
	}
	mx_r = tmp;
	if (mx_r >= mx_c) return true;
	return false;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> MAP[i][j];
		}
	}
	
	while (1) {

		if (MAP[r][c] == k) {
			cout << cnt;
			return 0;
		}
		if (cnt > 100) {
			cout << "-1";
			return 0;
		}

		if (check()) { //R연산
			for (int i = 1; i <= mx_r; i++) {
				v.clear();
				memset(arrCount, 0, sizeof(arrCount));
				for (int j = 1; j <= mx_c; j++) {
					arrCount[MAP[i][j]]++;
					//cout << "MAP: " << MAP[i][j] << " ";	
				}
				for (int j = 1; j <= mx_c; j++) {
					//cout << "Count: " << arrCount[j] << " ";
				}
				for (int j = 1; j <= 100; j++) {
					if (arrCount[j] != 0) {
						v.push_back({ j,arrCount[j] });
						//cout << "j: " << j << " Count: " << arrCount[j] << '\n';
					}
				}

				sort(v.begin(), v.end(), cmp_v); // 정의한 함수대로 정렬
				memset(MAP[i], 0, sizeof(MAP[i]));
				int k = 1;
				for (int j = 0; j < v.size(); j++) {
					int x = v[j].first;
					int y = v[j].second;
					//cout << "x: " << x << " y: " << y << '\n';
					MAP[i][k] = x;
					MAP[i][k + 1] = y;
					k += 2;
				}
			}
		}
		else { // C연산
			for (int i = 1; i <= mx_c; i++) {
				v.clear();
				memset(arrCount, 0, sizeof(arrCount));
				for (int j = 1; j <= mx_r; j++) {
					arrCount[MAP[j][i]]++;
				}
				for (int j = 1; j <= 100; j++) {
					if (arrCount[j] != 0) v.push_back({ j, arrCount[j] });
				}
				sort(v.begin(), v.end(), cmp_v);
				for (int j = 1; j <= mx_r; j++) {
					MAP[j][i] = 0;
				}
				int k = 1;
				for (int j = 0; j < v.size(); j++) {
					int x = v[j].first;
					int y = v[j].second;
					MAP[k][i] = x;
					MAP[k + 1][i] = y;
					k += 2;
				}
			}
		}
		cnt++;
	}
	return 0;
}