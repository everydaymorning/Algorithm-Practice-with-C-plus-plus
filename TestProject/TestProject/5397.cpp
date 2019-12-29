#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		stack<char> s1;
		stack<char> s2;

		int str_size = str.size();
		
		for (int j = 0; j < str_size; j++) {
			char c = str.at(j);
			if (c == '<') {
				if (s1.empty()) continue;
				else {
					char tmp = s1.top();
					s2.push(tmp);
					s1.pop();
				}
			}
			else if (c == '>') {
				if (s2.empty()) continue;
				else {
					char tmp = s2.top();
					s1.push(tmp);
					s2.pop();
				}
			}
			else if (c == '-') {
				if (s1.empty()) continue;
				else s1.pop();
			}
			else {
				s1.push(c);
			}


		}
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		string password;
		while (!s1.empty()) {
			password += s1.top();
			s1.pop();
		}
		reverse(password.begin(), password.end());
		cout << password << '\n';
		
	}
	return 0;
}