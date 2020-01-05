#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	string str;
	cin >> str;

	string res = str;
	int str_size = str.size();
	for (int i = 1; i < t; i++) {

		string tmp;
		cin >> tmp;

		for (int j = 0; j < str_size; j++) {
			if (str[j] != tmp[j]) {
				res[j] = '?';
			}
		}
	}
	
	cout << res;

	return 0;
}