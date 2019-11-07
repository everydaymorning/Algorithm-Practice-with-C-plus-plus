#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	int n;
	cin >> n;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push_front") {
			int t;
			cin >> t;
			dq.push_front(t);
		}
		else if (str == "push_back") {
			int t;
			cin >> t;
			dq.push_back(t);
		}
		else if (str == "pop_front") {
			if (dq.size() == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.size() == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << dq.size() << '\n';
		}
		else if (str == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (str == "front") {
			if (dq.size() == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (str == "back") {
			if (dq.size() == 0) {
				cout << "-1" << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}

	return 0;
}