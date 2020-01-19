#include <bits/stdc++.h>
using namespace std;

int paper[129][129];
int blue;
int white;

void divide(int n, int x, int y) {
	int check = paper[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (check == 0 && paper[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && paper[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				divide(n / 2, x, y);
				divide(n / 2, x + (n / 2), y);
				divide(n / 2, x, (y + n / 2));
				divide(n / 2, (x + n / 2), (y + n / 2));
				return;
			}
		}
	}

	if (check == 0) {
		white++;
	}
	else {
		blue++;
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

	divide(n, 0, 0);

	cout << white << '\n';
	cout << blue;

	return 0;
}