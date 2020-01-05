#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	int j = 1;
	int tmp = 0;
	bool flag = false;
	while (1) {
		int y = j;
		if (j % 2 == 0) {
			for (int i = 1; i <= j; i++) {
				tmp++;
				if (tmp == x) {
					printf("%d/%d", i, y);
					flag = true;
					break;
				}
				y--;
			}
		}
		else if (j % 2 == 1) {
			for (int i = 1; i <= j; i++) {
				tmp++;
				if (tmp == x) {
					printf("%d/%d", y, i);
					flag = true;
					break;
				}
				y--;
			}
		}
		j++;
		if (flag) break;
	}

	return 0;
}