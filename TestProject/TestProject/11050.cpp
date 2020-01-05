#include <bits/stdc++.h>
using namespace std;

int func(int a) {
	if (a == 0 || a == 1) return 1;
	return a * func(a - 1);
}
int main() {
	int n, k;
	cin >> n >> k;

	printf("%d", func(n) / (func(k) * func(n - k)));

	return 0;

}