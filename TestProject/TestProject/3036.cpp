#include <bits/stdc++.h>
using namespace std;
int arr[101];

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b!=0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int tmp = arr[0];

	for (int i = 1; i < n; i++) {
		cout << tmp / gcd(tmp, arr[i]) << "/" << arr[i] / gcd(tmp, arr[i]) << '\n';
	}

	return 0;
}