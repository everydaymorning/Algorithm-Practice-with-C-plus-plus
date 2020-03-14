#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string buf;
	getline(cin, buf);
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		string tmp;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				reverse(tmp.begin(), tmp.end());
				cout << tmp << " ";
				tmp.clear();
			}
			else {
				tmp += str[j];
			}
		}

		reverse(tmp.begin(), tmp.end());
		cout << tmp << '\n';
		tmp.clear();
	}
	return 0;
}