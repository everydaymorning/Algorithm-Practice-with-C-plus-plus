#include <bits/stdc++.h>

using namespace std;

int main() {
	int h1, h2;
	int max = 0;
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		cin >> h1 >> h2;
		tmp = tmp + h2 - h1;
		if (max < tmp) {
			max = tmp;
		}
		
	}

	printf("%d", max);

	return 0;
}