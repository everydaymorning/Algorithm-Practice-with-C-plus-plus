#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
void prime(int a, int b) {
	for (int i = 2; i <= b; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(b); i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= b; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = a; i <= b; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << '\n';
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	prime(a, b);

	return 0;
}