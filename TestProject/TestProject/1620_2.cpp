#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	map<string, int> MAP1;
	map<int, string> MAP2;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		MAP1[s] = i;
		MAP2[i] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			int num = stoi(s);
			cout << MAP2[num] << '\n';
		}
		else {
			cout << MAP1[s] << '\n';
		}
	}
	return 0;
}