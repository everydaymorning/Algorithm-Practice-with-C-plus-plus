#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long x, y, z;
	long long low, high, mid, tmp;
	cin >> x >> y;
	z = 100 * y / x;

	if (z >= 99) {
		cout << "-1";
		return 0;
	}
	low = 0;
	high = 1000000000;
	while (low <= high) {
		mid = (low + high) / 2;
		tmp = 100 * (y + mid) / (x + mid);
		
		if (tmp > z) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		//cout << "low: " << low << "  high: " << high << "  tmp: " << tmp << "  mid: " << mid << '\n';
	}
	cout << low;
	return 0;
}