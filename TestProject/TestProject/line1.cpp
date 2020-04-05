#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	vector<char> v;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '<' || str[i] == '[' || str[i] == '{') {
			v.push_back(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == '>' || str[i] == ']') {
			if (!v.empty()) {
				for (int j = 0; j < v.size(); j++) {
					if (v[j] == '(' && str[i] == ')') {
						ans++;
					}
					else if (v[j] == '<' && str[i] == '>') {
						ans++;
					}
					else if (v[j] == '[' && str[i] == ']') {
						ans++;
					}
					else if (v[j] == '{' && str[i] == '}') {
						ans++;
					}
				}
			}
		}
		
	}

	if (ans == 0) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
	return 0;
}