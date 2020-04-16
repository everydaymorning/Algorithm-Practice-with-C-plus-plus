#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int MAP[51][51];
int ans;
int main() {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < t; i++) {
		int x, d, K;
		cin >> x >> d >> K;

		for (int j = x; j <= n; j *= x) {
			if (d == 0) {
				for (int a = 0; a < K; a++) {
					int tmp = MAP[j][m];
					for (int k = m; k >= 2; k--) {
						MAP[j][k] = MAP[j][k - 1];
					}
					MAP[j][1] = tmp;
				}
			}
			else if (d == 1) {
				for (int a = 0; a < K; a++) {
					int tmp = MAP[j][1];
					for (int k = 1; k <= m - 1; k++) {
						MAP[j][k] = MAP[j][k + 1];
					}
					MAP[j][m] = tmp;
				}
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cout << MAP[j][k] << " ";
			}
			cout << '\n';
		}
		bool flag = false;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (MAP[j][k] == 0) continue;
				if (j == 1) {
					int idx1 = k - 1;
					int idx2 = k + 1;
					if (idx1 < 1) idx1 = m;
					if (idx2 > m) idx2 = 1;
					if (MAP[j][k] == MAP[j][idx1]) {
						MAP[j][k] = 0;
						MAP[j][idx1] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j][idx2]) {
						MAP[j][k] = 0;
						MAP[j][idx2] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j + 1][k]) {
						MAP[j][k] = 0;
						MAP[j + 1][k] = 0;
						flag = true;
					}
				}
				else if (j == n) {
					int idx1 = k - 1;
					int idx2 = k + 1;
					if (idx1 < 1) idx1 = m;
					if (idx2 > m) idx2 = 1;
					if (MAP[j][k] == MAP[j][idx1]) {
						MAP[j][k] = 0;
						MAP[j][idx1] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j][idx2]) {
						MAP[j][k] = 0;
						MAP[j][idx2] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j - 1][k]) {
						MAP[j][k] = 0;
						MAP[j - 1][k] = 0;
						flag = true;
					}
				}
				else {
					int idx1 = k - 1;
					int idx2 = k + 1;
					if (idx1 < 1) idx1 = m;
					if (idx2 > m) idx2 = 1;
					if (MAP[j][k] == MAP[j][idx1]) {
						MAP[j][k] = 0;
						MAP[j][idx1] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j][idx2]) {
						MAP[j][k] = 0;
						MAP[j][idx2] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j - 1][k]) {
						MAP[j][k] = 0;
						MAP[j - 1][k] = 0;
						flag = true;
					}
					else if (MAP[j][k] == MAP[j + 1][k]) {
						MAP[j][k] = 0;
						MAP[j + 1][k] = 0;
						flag = true;
					}
				}
			}
		}
		if (!flag) {
			int cnt = 0;
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (MAP[j][k] > 0) {
						sum += MAP[j][k];
						cnt++;
					}
					
				}
			}
			int avg = (int)sum / cnt;

			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (MAP[j][k] > avg) {
						MAP[j][k]--;
					}
					else if(MAP[j][k] <= avg && MAP[j][k] > 0){
						MAP[j][k]++;
					}
				}
			}
			
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cout << MAP[j][k] << " ";
			}
			cout << '\n';
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= m; k++) {
			if (MAP[j][k] > 0) ans += MAP[j][k];
		}
	}
	cout << ans;
	
	return 0;
}