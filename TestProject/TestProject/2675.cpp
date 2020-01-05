#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string str;
		cin >> str;
		int str_size = str.size();

		for (int i = 0; i < str_size; i++) {
			for (int j = 0; j < n; j++) {
				cout << str.at(i);
			}
		}
		cout << '\n';
	}

	return 0;
}