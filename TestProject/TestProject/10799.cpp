#include <bits/stdc++.h>

using namespace std;

int main() {

	string str;
	cin >> str;
	int str_len = str.size();
	stack<char> s;
	int stick = 0;
	int cnt = 0;
	char tmp = ' ';
	for (int i = 0; i < str_len; i++) {
		
		if (str[0] == ')') break;
		
		if (str[i] == '(') {
			s.push(str[i]);
			stick++;
			tmp = str[i];
		}
		else if (str[i] == ')') {
			if (s.top() == '(') {
				if (str[i] == tmp) {
					stick--;
					cnt += 1;
					s.pop();
				}
				else {
					s.pop();
					stick--;
					cnt += stick;
					tmp = str[i];
				}
				
			}
		}
		
	}

	cout << cnt << '\n';

	return 0;
}