#include <bits/stdc++.h>
using namespace std;

int main() {
	int num;
	cin >> num;

	int big = 5;
	int small = 3;
	int min_number = 0;
	if (num < small) {
		printf("-1");
		return 0;
	}

	int m = num / big;
	while (m >= 0) {
		int tmp = num - (m * big);
		if (tmp % 3 == 0) {
			min_number = m + (tmp / small);
			break;
		}
		m--;
	}
	if (m < 0) {
		min_number = -1;
	}

	printf("%d", min_number);
	return 0;
}