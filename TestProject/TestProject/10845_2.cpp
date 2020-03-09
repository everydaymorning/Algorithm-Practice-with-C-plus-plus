#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "pop") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
		else {
			int t;
			cin >> t;
			q.push(t);
		}
	}
	return 0;
}