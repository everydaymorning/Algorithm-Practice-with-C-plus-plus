#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	int cnt = 0;
	int stick = 64;

	while (x > 0) {
		if (stick > x) {
			stick /= 2;
		}
		else {
			x -= stick;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;


}