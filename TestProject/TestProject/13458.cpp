#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int b, c;
long long res;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		res++;
		arr[i] -= b;

		if (arr[i] > 0) {
			if (arr[i] % c == 0) {
				res += (arr[i] / c);
			}
			else {
				res += (arr[i] / c) + 1;
			}
		}

	}

	cout << res;
	return 0;
}