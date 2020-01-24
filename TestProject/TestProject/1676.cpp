#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		int tmp = i;

		while (tmp % 5 == 0 && tmp > 0) {
			cnt++;
			tmp /= 5;
		}
	}

	cout << cnt;
	return 0;
}