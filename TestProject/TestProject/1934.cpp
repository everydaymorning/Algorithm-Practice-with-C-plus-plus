#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int c = 0;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		
		int res = a * b / gcd(a, b);

		printf("%d\n", res);

	}

	return 0;
}