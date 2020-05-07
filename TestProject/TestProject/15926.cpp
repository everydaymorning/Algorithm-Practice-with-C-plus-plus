#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	stack<char> s;
	int num = 0;
	int mx = 0;
	bool flag = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			if (flag) {
				num = 0;
			}
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty()) {
				num = 0;
				continue;
			}
			if (s.top() == '(') {
				s.pop();
				num += 2;
				if (!s.empty() && s.top() == '(') {
					flag = true;
					continue;
				}
				flag = false;
			}
			mx = max(mx, num);
		}
	}
	mx = max(mx, num);
	cout << mx;
	return 0;
}