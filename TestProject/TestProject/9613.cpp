#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	long long c = 0;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	long long t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		long long sum = 0;
		long long arr[101] = { 0 };

		for (long long i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (long long i = 0; i < n - 1; i++) {
			for (long long j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}

		printf("%lld\n", sum);
	}

	return 0;
}