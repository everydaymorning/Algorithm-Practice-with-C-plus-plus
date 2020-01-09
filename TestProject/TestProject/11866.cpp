#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	deque<int> d;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	cout << "<";
	int cnt = 1;
	while (!d.empty()) {
		if (cnt == k) {
			int res = d.front();
			d.pop_front();
			cnt = 1;
			cout << res;
			if (d.size() > 0) {
				cout << ", ";
			}
			continue;
		}
		int tmp = d.front();
		d.pop_front();
		d.push_back(tmp);
		cnt++;


	}

	cout << ">";

	return 0;
}