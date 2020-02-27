#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	string tmp;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') tmp += str[i];
	}
	cout << tmp;
	return 0;
}