#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	int w, h;
	cin >> w >> h;

	int tmp = gcd(w, h);
	
	int w_tmp = w / gcd(w, h);
	int h_tmp = h / gcd(w, h);
	int sum = (w_tmp + h_tmp - 1) * 4;
	int res = w * h - sum;
	cout << res;
	return 0;
}