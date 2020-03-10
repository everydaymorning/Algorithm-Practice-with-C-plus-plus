#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		cout << upper_bound(v.begin(), v.end(), t) - lower_bound(v.begin(), v.end(), t) << " ";
	}
	return 0;
}