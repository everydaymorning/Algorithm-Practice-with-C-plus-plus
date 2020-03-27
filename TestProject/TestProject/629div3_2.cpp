#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		for (int i = 0; i < n; i++) {
			s += 'a';
		}
		
		for (int i = n - 2; i >= 0; i--) {
			if (k <= (n - i - 1)) {
				s[i] = 'b';
				s[n - k] = 'b';
				cout << s;
				break;
			}
			k -= (n - i - 1);
			cout << "k: " << k << '\n';
		}
	}
	return 0;
}