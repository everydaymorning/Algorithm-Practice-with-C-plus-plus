#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int sum = 0;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t != 0) {
			v.push_back(t);
		}
		else {
			v.pop_back();
		}
	}
	int v_size = v.size();
	if (v_size != 0) {
		for (int i = 0; i < v_size; i++) {
			sum += v.at(i);
		}
	}
	cout << sum;
	return 0;
}