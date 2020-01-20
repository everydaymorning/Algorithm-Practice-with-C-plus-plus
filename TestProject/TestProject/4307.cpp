#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int len, num;
		cin >> len >> num;
		vector<int> v;
		for (int i = 0; i < num; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		int mid = len / 2;
		int mx = 0;
		int mn = 0;
		
		for (int i = 0; i < num; i++) {
			if (v[i] > mid) {
				mn = max(mn, len - v[i]);
				mx = max(mx, v[i]);
			}
			else {
				mn = max(mn, v[i]);
				mx = max(mx, len - v[i]);
			}
		}

		cout << mn << " " << mx << '\n';
	}

	return 0;
}