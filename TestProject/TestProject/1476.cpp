#include <bits/stdc++.h>
using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;
	int a = 1, b = 1, c = 1;
	int year = 1;
	while (1) {
		if (e == 1 && s == 1 && m == 1) break;
		a++;
		b++;
		c++;
		if (a > 15) {
			a = 1;
		}
		if (b > 28) {
			b = 1;
		}
		if (c > 19) {
			c = 1;
		}
		year++;
		if (a == e && b == s && c == m) break;
	}

	printf("%d", year);

	return 0;
}