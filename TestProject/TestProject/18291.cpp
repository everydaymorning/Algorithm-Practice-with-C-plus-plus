#include <bits/stdc++.h>
using namespace std;
long long dp(long long x, long long y) {
	long long r;
	if (y == 0) return 1;
	else if (y == 1) return x;

	if (y % 2 == 0) {
		r = dp(x, y / 2);
		return r * r % 1000000007;
	}
	else {
		r = dp(x, (y - 1) / 2);
		return (r * r) * x % 1000000007;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		if (n == 1) cout << "1" << '\n';
		else cout << dp(2, n - 2) % 1000000007 << '\n';
	}
	return 0;
}