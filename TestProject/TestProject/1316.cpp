#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	int cnt = t;
	while (t--) {
		string str;
		cin >> str;
		bool flag = false;
		int str_size = str.size();
		bool check[26] = { 0 };
		for (int i = 1; i < str_size; i++) {
			if (str[i] != str[i-1]) {
				if (check[str[i] - 'a']) {
					cnt--;
					break;
				}
				check[str[i - 1] - 'a'] = true;
			}
		}

	}

	printf("%d", cnt);

	return 0;
}