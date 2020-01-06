#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	string tmp = str;
	reverse(str.begin(), str.end());
	if (str == tmp) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}