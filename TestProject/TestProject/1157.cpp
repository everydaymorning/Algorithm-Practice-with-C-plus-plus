#include <iostream>
using namespace std;

int main() {
	char str[1000001] = { '\0' };
	int tmp[26] = { 0 };
	cin >> str;
	
	for (int i = 0; i < 1000001; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == (char)('a' + j) || str[i] == (char)('A' + j)) {
				tmp[j]++;
			}
		}
	}

	int cnt = 0;
	int max = tmp[0];
	for (int i = 0; i < 26; i++) {
		if (tmp[i] > max) {
			max = tmp[i];
			cnt = i;
		}
		
	}
	int c = 0;
	for (int i = 0; i < 26; i++) {
		if (max == tmp[i]) {
			c++;
			if (c >= 2) {
				cout << "?";
				break;
			}
		}
		
	}

	if (c < 2) {
		cout << (char)('A' + cnt);
	}
	
	return 0;
}