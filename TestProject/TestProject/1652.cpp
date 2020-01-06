#include <bits/stdc++.h>
using namespace std;
char seat[101][101];
bool check[101];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> seat[i][j];
		}
	}

	int ver = 0, hor = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (seat[i][j] == 'X') {
				check[i] = false;
				continue;
			}

			if (seat[i][j] == '.' && !check[i]) {
				if (seat[i][j + 1] == '.') {
					check[i] = true;
					hor++;
				}
			}
		}
	}
	memset(check, false, sizeof(check));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (seat[i][j] == 'X') {
				check[j] = false;
				continue;
			}

			if (seat[i][j] == '.' && !check[j]) {
				if (seat[i + 1][j] == '.') {
					check[j] = true;
					ver++;
				}
			}
		}
	}

	printf("%d %d", hor, ver);

	return 0;
}