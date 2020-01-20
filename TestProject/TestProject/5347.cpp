#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	while (b) {
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;

}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		cout << lcm(a, b) << '\n';
	}

	return 0;
}