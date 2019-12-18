#include <bits/stdc++.h> //나중에 다시 풀기

using namespace std;
int arr[11][11];
bool check1[11][11];
bool check2[11][11];
int num;

void func(int _n, int cnt) {
	if (_n == cnt) {
		num++;
		return;
	}

	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _n; j++) {
			if (arr[i][j] != 0 && !check1[i][j + cnt] && !check2[i][j - cnt + _n - 1]) {
				check1[i][j + cnt] = true;
				check2[i][j - cnt + _n - 1] = true;
				func(_n, cnt + 1);
				check1[i][j + cnt] = false;
				check2[i][j - cnt + _n - 1] = false;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			int t;
			cin >> t;
			arr[i][j] = t;
		}
	}
	func(n, 0);
	printf("%d", num);
	return 0;
}