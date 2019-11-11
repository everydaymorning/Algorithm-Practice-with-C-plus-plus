#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	stack<pair<int, int>> s;

	for (int i = 1; i <= t; i++) {
		int a;
		cin >> a;

		while (!s.empty()) {
			if (s.top().second > a) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0 ";
		}

		s.push(make_pair(i, a));
	}
	
	return 0;
}