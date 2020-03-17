#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	string con;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') continue;
		con += str[i];
	}
	cout << con;
	return 0;
}