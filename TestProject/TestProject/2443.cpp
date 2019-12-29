#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = n; j > i; j--) {
			printf(" ");
		}
		for (int j = 2 * i - 1; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}