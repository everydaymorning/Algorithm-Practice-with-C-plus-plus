#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	

	while (t--) {
		int n;
		cin >> n;
		map<string, int> mp;
		while (n--) {
			string name, type;
			cin >> name >> type;

			mp[type]++;
		}

		int res = 1;
		map<string, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++) {
			res *= (it->second + 1);
		}
		res -= 1;

		cout << res << '\n';

	}
	return 0;
}