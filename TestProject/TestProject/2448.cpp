#include <bits/stdc++.h>

using namespace std;
char box[3072][6144];


void func(int size, int x, int y) {
	

	if (size == 3) {
		box[x][y] = '*';
		box[x + 1][y - 1] = '*';
		box[x + 1][y + 1] = '*';
		box[x + 2][y - 2] = '*';
		box[x + 2][y - 1] = '*';
		box[x + 2][y] = '*';
		box[x + 2][y + 1] = '*';
		box[x + 2][y + 2] = '*';

		return;
	}

	func(size / 2, x, y);
	func(size / 2, x + (size / 2), y - (size / 2));
	func(size / 2, x + (size / 2), y + (size / 2));
	
}
int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (j == 2 * n - 1) {
				box[i][j] = '\0';
			}
			else {
				box[i][j] = ' ';
			}
		}
		
	}

	func(n, 0, n -1);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n -1; j++) {
			printf("%c", box[i][j]);
		}
		printf("\n");
	}

	return 0;
}
