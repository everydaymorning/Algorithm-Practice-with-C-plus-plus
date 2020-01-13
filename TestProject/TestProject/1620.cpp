#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	
	map<int, string> mp1;
	map<string, int> mp2;

	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		mp1[i] = tmp;
		mp2[tmp] = i;
	}

	for (int i = 1; i <= m; i++) {
		string t;
		cin >> t;
		if (t[0] >= '0' && t[0] <= '9') {
			int t_num = atoi(t.c_str());
			cout << mp1[t_num] << '\n';
		}
		else {
			cout << mp2[t] << '\n';
		}
	}
	return 0;
}