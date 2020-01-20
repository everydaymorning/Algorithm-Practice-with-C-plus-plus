#include <bits/stdc++.h>
using namespace std;
string serial[1001];

bool cmp(string x, string y) {
	if (x.length() != y.length()) {
		return x.length() < y.length();
	}
	else {
		int numX = 0;
		int numY = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x[i] - '0' > 0 && x[i] - '0' < 10) {
				numX += (x[i] - '0');
			}
			if (y[i]  - '0' > 0 && y[i] - '0'< 10) {
				numY += (y[i] - '0');
			}
		}
		if (numX != numY) {
			return numX < numY;
		}
		else {
			return x < y;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> serial[i];
	}
	
	sort(serial, serial + t, cmp);

	for (int i = 0; i < t; i++) {
		cout << serial[i] << '\n';
	}
	return 0;

}