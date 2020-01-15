#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	int cnt = 0;
	int str_size = str.size();
	stack<char> s;
	for (int i = 0; i < str_size; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			s.pop();
			if (str[i - 1] == '(') {
				cnt += s.size();
			}
			else {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}