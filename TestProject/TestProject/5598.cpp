#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	string con;
	for (int i = 0; i < str.size(); i++) {
		char tmp = str[i] - 3;
		if (tmp < 65) tmp += 26;
		con += tmp;
	}
	cout << con;
	return 0;
}