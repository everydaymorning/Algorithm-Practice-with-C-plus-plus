#include <bits/stdc++.h>
using namespace std;

string str[51];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	int mx = 1;
	for (int k = 1; k < n; k++) {
		int cnt = k + 1;
		for (int i = 0; i < n - k; i++) {
			for (int j = 0; j < m - k; j++) {
				if (str[i][j] == str[i + k][j + k] && str[i][j] == str[i][j+k] && str[i][j] == str[i+k][j]) {
					mx = (int)pow(cnt, 2);
				}
			}
		}
	}

	cout << mx;
	return 0;
}