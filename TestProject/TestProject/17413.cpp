#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	getline(cin, str);
	string tmp;
	bool flag = false;
	for (int i = 0; i < str.size(); i++) {
		
		if (str[i] == '<') {
			if (!tmp.empty()) {
				reverse(tmp.begin(), tmp.end());
				cout << tmp;
				tmp.clear();
				tmp += str[i];
			}
			else {
				tmp += str[i];
			}
			flag = true;
		}
		else if (str[i] == '>' && tmp[0] == '<') {
			tmp += str[i];
			cout << tmp;
			tmp.clear();
			flag = false;
		}
		else if (str[i] == ' ') {
			if (flag) {
				tmp += str[i];
				continue;
			}
			reverse(tmp.begin(), tmp.end());
			cout << tmp << " ";
			tmp.clear();
		}
		else tmp += str[i];

		
	}
	reverse(tmp.begin(), tmp.end());
	cout << tmp;
	tmp.clear();
	return 0;
}