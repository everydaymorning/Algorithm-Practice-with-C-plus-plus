#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		int tmp = a % b;
		if (tmp == 0) {
			cout << tmp << '\n';
			continue;
		}
		int res = abs(tmp - b);
		cout << res << '\n';
	}

	return 0;
}