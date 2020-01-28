#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	int a1, b1, c1, d1;
	a1 = a * d;
	b1 = b * d;
	c1 = c * b;
	int x = a1 + c1;
	
	
	int r = gcd(x, b1);
	x /= r;
	b1 /= r;
	cout << x << " " << b1;
	return 0;
	
	
}