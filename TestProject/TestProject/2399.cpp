#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long res = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			res += abs(v[i] - v[j]);
		}
	}
	cout << res;
	return 0;
}