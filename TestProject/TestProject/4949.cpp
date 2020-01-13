#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (1) {
		string str;
		getline(cin, str);
		if (str.length() == 1 && str[0] == '.') break;
		stack<char> s;
		bool flag = false;
		int str_size = str.size();
		for (int i = 0; i < str_size; i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					flag = true;
					s.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			else {
				flag = true;
			}
		}

		

		if (s.empty() && flag) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}

	}

	return 0;
}