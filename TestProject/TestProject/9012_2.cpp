#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		stack<char> s;
		string tmp;
		cin >> tmp;

		bool vps = true;
		for (int j = 0; j < tmp.length(); j++) {
			char t = tmp[j];
			if (t == '(') {
				s.push(t);
			}
			else {
				if (s.size() == 0) {
					vps = false;
					break;
				}
				if (s.top() == '(') {
					s.pop();
					continue;
				}
				else {
					vps = false;
					break;
				}
			}
		}
		if (s.size() > 0) vps = false;

		if (vps) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}