#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int result = 0;
	int str_len = str.length();
	for (int i = 0; i < str_len; i++) {
		int a = str[i] -'0';
		result += a;
	}

	cout << result << '\n';

	return 0;
}