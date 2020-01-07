#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	nth_element(v.begin(), v.begin() + m - 1, v.end());
	
	printf("%d", v.at(m - 1));

	return 0;
}