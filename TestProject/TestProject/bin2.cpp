#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 100000;
const long long MAX_TIME = 1000000000;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int m;
	cin >> m;

	long long low = 0;
	long long high = MAX_N * MAX_TIME;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += mid / v[i];
		}
		cout << "mid: " << mid << "  sum: " << sum << '\n';
		if (sum < m) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << "low: " << low << "  high: " << high << '\n';
	return 0;

}