#include <bits/stdc++.h>
using namespace std;

int main() {

	stack<int> s;
	int n;
	cin >> n;

	string tmp;
	getline(cin, tmp);
	string str;
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		
			if (str == "pop") {
				if (s.size() == 0) {
					cout << "-1" << '\n';
					continue;
				}
				cout << s.top() << '\n';
				s.pop();
			}
			else if (str == "size") {
				cout << s.size() << '\n';
			}
			else if (str == "empty") {
				cout << s.empty() << '\n';
			}
			else if (str == "top") {
				if (s.size() == 0) {
					cout << "-1" << '\n';
					continue;
				}
				cout << s.top() << '\n';
			}
			else {
				int t;
				cin >> t;
				s.push(t);
			}
		}
	return 0;
}