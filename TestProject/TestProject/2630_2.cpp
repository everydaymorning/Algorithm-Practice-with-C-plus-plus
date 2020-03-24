#include <bits/stdc++.h>
using namespace std;
int MAP[129][129];
int blue, white;
void dnc(int n, int s, int e) {
	int tmp = MAP[s][e];
	bool flag = true;
	for (int i = s; i < s + n; i++) {
		for (int j = e; j < e + n; j++) {
			if (tmp != MAP[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) {
		if (tmp == 0) {
			white++;
		}
		else if (tmp == 1) {
			blue++;
		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				dnc(n / 2, s + (i * n / 2), e + (j * n / 2));
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> MAP[i][j];
		}
	}

	dnc(n, 0, 0);
	cout << white << '\n' << blue;
	return 0;
}