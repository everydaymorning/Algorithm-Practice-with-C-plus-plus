#include <bits/stdc++.h>
using namespace std;
int arr[246913];

int prime(int n) {
	int cnt = 0;
	for (int i = 2; i <= 2 * n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(2*n); i++) {
		if (arr[i] == 0) continue;

		for (int j = i+i; j <= 2 * n; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = n+1; i <= 2 * n; i++) {
		if (arr[i] != 0) {
			cnt++;
		}
	}

	return cnt;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		int a;
		cin >> a;
		if (a == 0) break;
		cout << prime(a) << '\n';
		
	}

	return 0;
}