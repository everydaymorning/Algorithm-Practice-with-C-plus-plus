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

	sort(v.begin(), v.end());
	int sum = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		total += sum;
	}
	cout << total;
	return 0;
}