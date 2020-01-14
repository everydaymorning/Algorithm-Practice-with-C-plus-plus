#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int word = 0;
	while (n--) {
		string str;
		cin >> str;
		int str_size = str.size();
		stack<char> s;
		for (int i = 0; i < str_size; i++) {
			
			if (!s.empty() && s.top() == str[i]) {
				s.pop();
				continue;
			}
			if (str[i] == 'A' || str[i] == 'B') {
				s.push(str[i]);
			}
			
		}
		if (s.empty()) word++;

	}

	cout << word;

	return 0;
}