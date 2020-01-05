#include <bits/stdc++.h>

using namespace std;

int main() {
	string str;
	cin >> str;

	int str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		cout << str[i];
		if ((i+1) % 10 == 0) {
			cout << '\n';
		}
	}

	return 0;
}