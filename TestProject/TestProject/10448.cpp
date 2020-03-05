#include <bits/stdc++.h>
using namespace std;
int t, sum;
vector<int> v;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	int n = 1;
	while (1) {
		int total = (n * (n + 1)) / 2;
		v.push_back(total);
		n++;
		if (total > 1000) break;
	}

	while (t--) {
		cin >> sum;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < v.size(); k++) {
					if (v[i] + v[j] + v[k] == sum) {
						flag = true;
					}
				}
			}
		}
		if (flag) cout << "1" << '\n';
		else cout << "0" << '\n';

	}
	return 0;
}