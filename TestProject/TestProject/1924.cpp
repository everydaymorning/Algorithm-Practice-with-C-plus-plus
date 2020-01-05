#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	char day[7][7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI" , "SAT" };

	int res = 0;
	for (int i = 1; i <= x; i++) {
		if (i == x) {
			res += y;
			break;
		}
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			res += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			res += 30;
		}
		else if (i == 2) {
			res += 28;
		}
	}

	printf("%s", day[res % 7]);

	return 0;
}