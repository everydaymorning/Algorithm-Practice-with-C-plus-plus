#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	while (n > 1) {
		if (n % 2 == 1) {
			str += '1';
		}
		else {
			str += '0';
		}
		n /= 2;
	}
	str += '1';
	reverse(str.begin(), str.end());
	cout << str << '\n';
	bool flag = false;
	int MAX = 0;
	int cnt = 0;
	int one = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			one++;
			if (one == 2) {
				MAX = max(cnt, MAX);
				cnt = 0;
				one -= 1;
			}
		}
		else if (str[i] == '0') {
			cnt++;
		}

	}
	cout << MAX;
	return 0;
}