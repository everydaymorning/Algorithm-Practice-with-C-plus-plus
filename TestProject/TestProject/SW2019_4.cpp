#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n) {
		if (n % 2 == 0) n /= 2;
		else {
			n -= 1;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}