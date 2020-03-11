#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (i % j == 0) {
				tmp++;
			}
		}
		if (tmp == 2) cnt++;
	}
	cout << cnt;
	return 0;
}