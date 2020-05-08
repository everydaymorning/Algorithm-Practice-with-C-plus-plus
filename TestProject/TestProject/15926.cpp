#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	stack<int> s;
	int mx = 0;
	s.push(-1);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(i);
		else {
			s.pop();
			if (!s.empty()) {
				mx = max(mx, i - s.top());
			}
			else {
				s.push(i);
			}
		}
	}
	cout << mx;
	return 0;
}