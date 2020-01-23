#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n <= 3 * i * (i - 1) + 1) {
			cout << i;
			break;
		}
	}

	return 0;
}