#include <bits/stdc++.h>
using namespace std;
int n, L;
int MAP[101][101];
int main() {
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		int len = 1;
		for (int j = 0; j < n - 1; j++) {
			if (MAP[i][j] == MAP[i][j + 1]) len++;
			else if (MAP[i][j] + 1 == MAP[i][j + 1]) {
				if (len >= L) len = 1;
				else {
					flag = false;
					break;
				}
			}
			else if (MAP[i][j] == MAP[i][j + 1] + 1) {
				int tmp = MAP[i][j + 1];
				for (int k = j + 1; k < j + 1 + L; k++) {
					if (tmp != MAP[i][k]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					j += L - 1;
					len = 0;
				}
			}
			else if (abs(MAP[i][j] - MAP[i][j + 1]) >= 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		int flag = true;
		int len = 1;
		for (int j = 0; j < n - 1; j++) {
			if (MAP[j][i] == MAP[j + 1][i]) len++;
			else if (MAP[j][i] + 1 == MAP[j + 1][i]) {
				if (len >= L) len = 1;
				else {
					flag = false;
					break;
				}
			}
			else if (MAP[j][i] == MAP[j + 1][i] + 1) {
				int tmp = MAP[j + 1][i];
				for (int k = j + 1; k < j + 1 + L; k++) {
					if (tmp != MAP[k][i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					j += L - 1;
					len = 0;
				}
			}
			else if (abs(MAP[j][i] - MAP[j + 1][i]) >= 2) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}