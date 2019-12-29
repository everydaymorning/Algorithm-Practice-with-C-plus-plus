#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int front = 0, back = 0;
		for (int j = 0; j < 4; j++) {
			int t;
			
			cin >> t;

			if (t == 0) {
				front++;
			}
			else if (t == 1) {
				back++;
			}


		}

		if (front == 1 && back == 3) {
			printf("A\n");
		}
		else if (front == 2 && back == 2) {
			printf("B\n");
		}
		else if (front == 3 && back == 1) {
			printf("C\n");
		}
		else if (front == 4) {
			printf("D\n");
		}
		else {
			printf("E\n");
		}
	}
	return 0;
}