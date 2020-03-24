#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, d;

	cin >> x >> y >> d;
	int tmp = y - x;
	int res = tmp / d + 1;
	cout << res;
	return 0;
}