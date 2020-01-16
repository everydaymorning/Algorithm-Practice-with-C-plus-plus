#include <bits/stdc++.h>

using namespace std;

int a, b, c;

long long pow(int A, int B, int C) {
	if (B == 1) {
		return A;
	}
	else {
		long long tmp = pow(A, B / 2, C);
		if (B % 2 == 0) {
			return (tmp * tmp) % C;
		}
		else {
			return ((tmp * tmp) % C * A) % C;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> a >> b >> c;

	cout << pow(a % c, b, c);
	return 0;

}