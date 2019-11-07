#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	queue<int> q;
	cin >> n;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "pop") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			cout << q.empty() << '\n';
		}
		else if (str == "front") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (str == "back") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
		else {
			int t;
			cin >> t;
			q.push(t);
		}
	}
	return 0;
}