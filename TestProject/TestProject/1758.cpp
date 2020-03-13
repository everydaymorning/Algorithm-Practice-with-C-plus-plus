#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());

	long long result = 0;
	for (int i = 1; i <= n; i++) {
		long long tmp = (v[i - 1] - (i - 1));
		if (tmp > 0) result += tmp;
	}
	cout << result;
	return 0;
}