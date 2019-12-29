#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum_y = 0;
	int sum_m = 0;
	for (int i = 0; i < n; i++) {
		int phone;
		cin >> phone;

		int y = (1 + (phone / 30)) * 10;
		int m = (1 + (phone / 60)) * 15;
		if (phone == 0) {
			y = 0;
			m = 0;
		}
		sum_y += y;
		sum_m += m;
		
	}

	if (sum_y < sum_m) {
		printf("Y %d", sum_y);
	}
	else if (sum_y == sum_m) {
		printf("Y M %d", sum_y);
	}
	else if (sum_y > sum_m) {
		printf("M %d", sum_m);
	}

	return 0;
}