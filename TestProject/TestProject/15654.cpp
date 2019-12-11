#include <bits/stdc++.h>
using namespace std;

bool check[9];
int arr[9];
int arr2[9];
void func(int _n, int _m, int cnt) {
	if (_m == cnt) {
		for (int i = 0; i < _m; i++) {

			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	if (_m < cnt) {
		return;
	}
	for (int i = 0; i < _n; i++) {
		if (!check[i]) {
			check[i] = true;
			arr[cnt] = arr2[i];
			func(_n, _m, cnt + 1);
			check[i] = false;
		}
		

	}
}
int main() {
	int n, m;
	
	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr2[i] = a;
	}
	sort(arr2, arr2 + n);
	func(n, m, 0);

	return 0;
}