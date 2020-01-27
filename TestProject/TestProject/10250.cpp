#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, h, w, n;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> h >> w >> n;
		if (n % h == 0) {
			a = h;
			b = n / h;
		}
		else {
			a = n % h;
			b = n / h + 1;
		}
		string str_a = to_string(a);
		string str_b = to_string(b);
		if (b < 10) str_b = "0" + str_b;

		string res = str_a + str_b;
		cout << res << '\n';
	}
	
	return 0;


}