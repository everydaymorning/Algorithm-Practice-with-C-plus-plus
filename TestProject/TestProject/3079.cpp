#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 100001;
const long long MAX_TIME = 1000000001;
vector<long long> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	long long MAX = *max_element(v.begin(), v.end());
	long long low = 1;
	long long high = m * MAX;
	long long res = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;

		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += mid / v[i];
		}

		if (sum < m) {
			low = mid + 1;
		}
		else {
			res = mid;
			high = mid - 1;
		}
	}

	cout << res;
	return 0;
}