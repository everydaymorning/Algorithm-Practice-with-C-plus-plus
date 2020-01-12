#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> v;
	vector<int> cnt;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	cin >> m;
	sort(v.begin(), v.end());

	vector<int>::iterator low, up;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		low = lower_bound(v.begin(), v.end(), t);
		up = upper_bound(v.begin(), v.end(), t);
		int tmp = up - low;
		cnt.push_back(tmp);
		
	}

	for (int i = 0; i < m; i++) {
		cout << cnt.at(i) << " ";
	}
	return 0;

}