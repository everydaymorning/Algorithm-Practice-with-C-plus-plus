#include <bits/stdc++.h>
using namespace std;
int paper[2188][2188];
int result[3];
void dnc(int n, int s, int e) {
	bool check = true;
	int tmp = paper[s][e];
	for (int i = s; i < s + n; i++) {
		for (int j = e; j < e + n; j++) {
			if (tmp != paper[i][j]) {
				check = false;
				break;
			}
		}
		if (!check) break;
	}

	if (check) {
		if (tmp == -1) {
			result[0]++;
		}
		else if (tmp == 0) {
			result[1]++;
		}
		else if (tmp == 1) {
			result[2]++;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				dnc(n / 3, s + (i * n / 3), e + (j * n / 3));
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
			cin >> paper[i][j];
		}
	}

	dnc(n, 0, 0);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}