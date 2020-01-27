#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, a, b;
	cin >> n >> a >> b;
	int cnt = 1;
	while (n) {
		if ((a + 1) / 2 == (b + 1) / 2) {
			break;
		}
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		n /= 2;
		cnt++;
	}
	if (!n) {
		cout << "-1";
	}
	else {
		cout << cnt;
	}
	return 0;
}