#include <bits/stdc++.h>
using namespace std;

int box[5222][5222];
void func(int size, int x, int y) {
	if (size == 1) {
		box[x][y] = 1;
		return;
	}
	int size2 = size / 3;

	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 && j != 1) func(size2, x + size2 * i, y + size2 * j);
			
		}
	}

	return;
}


int main() {
	int n;
	cin >> n;

	func(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (box[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << '\n';
	}


	return 0;
}