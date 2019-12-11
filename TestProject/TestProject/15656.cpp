#include <bits/stdc++.h>

using namespace std;
int arr2[9];
int arr[9];
void func(int _n, int _m, int cnt) {
	if (_m == cnt) {
		for (int i = 0; i < _m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	if (_m > cnt) {
		for (int i = 0; i < _n; i++) {
			arr[cnt] = arr2[i];
			func(_n, _m, cnt + 1);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr2[i] = t;
	}
	sort(arr2, arr2 + n);
	func(n, m, 0);

	return 0;
}