#include <bits/stdc++.h>
using namespace std;
int MAP[65][65];

void dnc(int n, int s, int e) {
	bool flag = true;
	int tmp = MAP[s][e];
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
		cout << tmp;
	}
	else {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				dnc(n / 2, s + (i * n / 2), e + (j * n / 2));
			}

		}
		cout << ")";
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			MAP[i][j] = tmp - '0';
		}
	}

	dnc(n, 0, 0);

	return 0;

}