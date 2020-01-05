#include <bits/stdc++.h>
using namespace std;

int main() {

	string word[5];
	int mx = 0;
	for (int i = 0; i < 5; i++) {
		cin >> word[i];
		int str_size = word[i].size();
		if (mx < str_size) mx = str_size;
	}
	string tmp;
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < 5; j++) {
			int len = word[j].size();
			if (len > i) tmp += word[j].at(i);
		}
	}
	cout << tmp;
	return 0;
}