#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int str_len = str.size();
	stack<char> s;
	//char tmp = ' ';
	int result = 0;

	for (int i = 0; i < str_len; i++) {
		if (str_len < 1 || str_len >30) {
			cout << "0" << '\n';
			break;
		}

		if (str[i] == '(') {
			s.push(str[i]);
	
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			
		}
		else if (str[i] == ')') {
			if (s.top() == '[') {
				cout << "0" << '\n';
				break;
			}
			else if (s.top() == '(') {
				s.pop();

			}
		}
		else if (str[i] == ']') {
			if (s.top() == '(') {
				cout << "0" << '\n';
				break;
			}
			else if (s.top() == '[') {
				s.pop();
			}
		}

	}
}