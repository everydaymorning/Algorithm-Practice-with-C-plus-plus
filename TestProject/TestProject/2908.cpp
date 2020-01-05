#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int a = atoi(str1.c_str());
	int b = atoi(str2.c_str());

	if (a > b) {
		printf("%d", a);
	}
	else {
		printf("%d", b);
	}

	return 0;
}