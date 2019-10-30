#include <iostream>

using namespace std;

int main() {
	int t;
	int a, b;
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int mod = 1;
		for (int j = 0; j < b; j++) {
			mod *= a;
			mod %= 10;
		}

		if (mod != 0) {
			printf("%d\n", mod);
		}
		else {
			printf("10\n");
		}

	}
	
	return 0;
}