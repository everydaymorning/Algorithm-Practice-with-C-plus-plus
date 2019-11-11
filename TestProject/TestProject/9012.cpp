#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		stack<char> s;
		int str_len = str.length();

		if (str_len < 2 || str_len > 50) break;

		bool vps = false;
		bool r = false;
		

		for (int j = 0; j < str_len; j++) {
			if (str[0] == ')') {
				r = true;
				break;
			}

			if (str[j] == '(') {
				s.push(str[j]);
				
			}
			else if (str[j] == ')') {
				if (!s.empty()) {
					s.pop();
				}
				else {
					r = true;
				}
			}
		}
		
		if (s.empty() && r == false) {
			vps = true;
		}
	

		
		if (vps) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		
		
	}

	return 0;
}