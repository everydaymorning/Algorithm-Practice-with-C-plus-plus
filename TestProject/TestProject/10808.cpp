#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r' ,'s', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int cnt[26] = { 0 };
	int len_s = s.length();
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < len_s; j++) {
			if (s.at(j) == alphabet[i]) {
				cnt[i]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", cnt[i]);
	}

	return 0;
}