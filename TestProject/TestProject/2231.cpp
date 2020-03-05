#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int sum = i;
		int tmp = i;
		while (tmp) {
			//cout << "tmp: " << tmp << '\n';
			sum += (tmp % 10);
			tmp /= 10;
		}
		//cout << "sum: " << sum << '\n';
		if (sum == n) {
			res = i;
			break;
		}
	}
	if (res == 0) cout << "0";
	else cout << res;
	return 0;
}