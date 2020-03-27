#include <bits/stdc++.h>
using namespace std;
char str[100001];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int cnt = n - 2;
		vector<string> res;
		vector<char> v;
		for (int i = 0; i < cnt; i++) {
			v.push_back('a');
		}
		for (int i = 0; i < 2; i++) {
			v.push_back('b');
		}

		do {
			for (int i = 0; i < n; i++) {
				str[i] = v[i];
			}
			res.push_back(str);
		} while (next_permutation(v.begin(), v.end()));

		cout << res[k - 1] << '\n';
		memset(str, 0, sizeof(str));
	}
	return 0;
}