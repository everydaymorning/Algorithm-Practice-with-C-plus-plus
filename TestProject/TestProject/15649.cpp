#include <bits/stdc++.h>

using namespace std;

void func(int _n, int _m, int* _arr, bool* _visit, int cnt) {

	if (_m == cnt) {
		for (int i = 0; i < _m; i++) {
			printf("%d ", _arr[i] + 1);
		}
		printf("\n");
	}

	for (int i = 0; i < _n; i++) {
		if (!_visit[i]) {
			_visit[i] = true;
			_arr[cnt] = i;
			func(_n, _m, _arr, _visit, cnt + 1);
			_visit[i] = false;
		}
	}
}
int main() {

	int n, m;
	cin >> n >> m;
	int arr[9] = { 0 };
	bool visit[9] = { 0 };

	func(n, m, arr, visit, 0);

	return 0;
}