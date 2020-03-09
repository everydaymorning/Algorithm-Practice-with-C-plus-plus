#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		
		if (str == "top") {
			if (s.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			if (s.size() == 0) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (str == "pop") {
			if (s.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else {
			int t;
			cin >> t;
			s.push(t);
		}
	}
	return 0;
}