#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	string tmp;

	int str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		if (str[i] == ' ') {
			tmp += ' ';
			continue;
		}

		if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] + 13 > 'z') {
				tmp += str[i] - 13;
			}
			else {
				tmp += str[i] + 13;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] + 13 > 'Z') {
				tmp += str[i] - 13;
			}
			else {
				tmp += str[i] + 13;
			}
		}
		else {
			tmp += str[i];
		}
	}

	cout << tmp;
	return 0;
}