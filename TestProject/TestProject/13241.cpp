#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		long long int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
long long int lcm(long long int a, long long int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long int a, b;
	cin >> a >> b;

	cout << lcm(a, b);

	return 0;
}