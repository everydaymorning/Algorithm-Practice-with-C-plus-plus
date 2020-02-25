#include <bits/stdc++.h>
using namespace std;
char MAP[9][9];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> MAP[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0 && j % 2 == 0 && MAP[i][j] == 'F') {
				cnt++;
			}
			else if (i % 2 == 1 && j % 2 == 1 && MAP[i][j] == 'F') {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}