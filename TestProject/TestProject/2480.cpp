#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		if (a == b) {
			printf("%d", 10000 + a * 1000);
		}
		else if (b == c) {
			printf("%d", 10000 + b * 1000);
		}
	}
	else if (a == b || b == c || a == c) {
		if (a == b) {
			printf("%d", 1000 + a * 100);
		}
		else if (b == c) {
			printf("%d", 1000 + b * 100);
		}
		else {
			printf("%d", 1000 + a * 100);
		}
	}
	else {
		int big = max(max(a, b), c);
		printf("%d", big * 100);
	}

	return 0;
}