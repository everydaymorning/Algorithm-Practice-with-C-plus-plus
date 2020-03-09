#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	cin >> str;

	list<char> l;
	for (int i = 0; i < str.size(); i++) {
		l.push_back(str[i]);
	}
	list<char>::iterator cur = l.end();

	int n;
	cin >> n;

	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < n; i++) {
		string tmp1;
		getline(cin, tmp1);
		if (tmp1[0] == 'L') {
			if (cur != l.begin()) cur--;
		}
		else if (tmp1[0] == 'D') {
			if (cur != l.end()) cur++;
		}
		else if (tmp1[0] == 'B') {
			if (cur != l.begin()) {
				cur--;
				cur = l.erase(cur);
			}
		}
		else {
			l.insert(cur, tmp1[2]);
		}
	}
	list<char>::iterator it;

	for (it = l.begin(); it != l.end(); it++) {
		cout << *it;
	}
	return 0;
}