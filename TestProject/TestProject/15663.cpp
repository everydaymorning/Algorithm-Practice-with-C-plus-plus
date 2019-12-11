#include <bits/stdc++.h>
using namespace std;

int arr[9];
int arr2[9];
bool check[9];

void func(int _n, int _m, int cnt) {
	if (_m == cnt) {

		for (int i = 0; i < _m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	bool chk_idx[10001] = { 0 };
	if (_m > cnt) {
		for (int i = 0; i < _n; i++) {
			
			if (!check[i] && !chk_idx[arr2[i]]) {
				chk_idx[arr2[i]] = true;
				check[i] = true;
				arr[cnt] = arr2[i];
				func(_n, _m, cnt + 1);
				check[i] = false;
			}
			
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