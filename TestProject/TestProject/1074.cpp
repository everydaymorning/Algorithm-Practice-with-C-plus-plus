#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int cnt;
void func(int size, int y, int x) {
	if (size == 1) {
		if (y == r && x == c) {
			cout << cnt << '\n';
			return;
		}
		cnt++;
		if (y == r && x + 1== c) {
			cout << cnt << '\n';
			return;
		}
		cnt++;
		if (y + 1 == r && x == c) {
			cout << cnt << '\n';
			return;
		}
		cnt++;
		if (y + 1 == r&& x + 1 == c) {
			cout << cnt << '\n';
			return;
		}
		cnt++;
		
	}
	else {
		func(size / 2, y, x);
		func(size / 2, y, x + size);
		func(size / 2, y + size, x);
		func(size / 2, y + size, x + size);
	}
	
}
int main() {
	cin >> n >> r >> c;
	int size = 1;
	for (int i = 1; i < n; i++) {
		size *= 2;
	}
	func(size, 0, 0);

	return 0;
	
}