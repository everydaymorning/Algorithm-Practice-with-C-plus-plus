#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	int n, m;
	scanf_s("%d:%d", &n, &m);

	int g = gcd(n, m);
	printf("%d:%d", n / g, m / g);

	return 0;

}