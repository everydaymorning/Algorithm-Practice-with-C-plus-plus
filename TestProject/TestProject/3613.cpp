#include <bits/stdc++.h>
using namespace std;
char res[101];
int main() {
	bool java = false; // false¸é C++; ture¸é java
	bool c = false;
	bool err = false;
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			java = true;
		}
		else if (str[i] == '_') {
			cnt++;
			c = true;
		}
	}
	int idx = 0;
	if (!(str[0] >= 'a' && str[0] <= 'z')) {
		err = true;
	}
	if (str[str.size() - 1] == '_') {
		err = true;
	}
	if (java && c) {
		err = true;
	}

	if (java == false && c == false) {
		cout << str;
		return 0;
	}
	if (java) {
		for (int i = 0; i < str.size(); i++) {
			
			if (str[i] >= 'A' && str[i] <= 'Z') {
				res[idx] = '_';
				str[i] = tolower(str[i]);
				res[++idx] = str[i];
				idx++;
				continue;
			}
			res[idx] = str[i];
			idx++;
		}
	}
	else if(c) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '_') {
				if (str[i + 1] == '_') {
					err = true;
					break;
				}
				str[i + 1] = toupper(str[i + 1]);
				res[idx] = str[i + 1];
				continue;
			}
			res[idx] = str[i];
			idx++;
		}
	}
	if (err) {
		cout << "Error!";
	}
	else {
		for (int i = 0; i < idx; i++) {
			cout << res[i];
		}
	}
	return 0;
}