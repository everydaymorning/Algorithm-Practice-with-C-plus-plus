#include <bits/stdc++.h>
using namespace std;

bool check[9];
int arr[9];

void func(int _n, int _m, int cnt) {
	if (_m == cnt) {

		for (int i = 0; i < _m; i++) {

			printf("%d ", arr[i] + 1);

		}
		printf("\n");
	}

	if (_m < cnt) {
		return;
	}
	for (int i = 0; i < _n; i++) {
			
			arr[cnt] = i;

			func(_n, _m, cnt + 1);
		
	}
}
int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;

	func(n, m, 0);

	return 0;
}