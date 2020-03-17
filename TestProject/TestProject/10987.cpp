#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o') cnt++;
	}
	cout << cnt;
	return 0;
}