#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	string tmp1, tmp2, tmp3, tmp4;

	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == '5') {
			tmp1 += '6';
			continue;
		}
		tmp1 += str1[i];
	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] == '5') {
			tmp2 += '6';
			continue;
		}
		tmp2 += str2[i];
	}

	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == '6') {
			tmp3 += '5';
			continue;
		}
		tmp3 += str1[i];
	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] == '6') {
			tmp4 += '5';
			continue;
		}
		tmp4 += str2[i];

	}
	int MAX = stoi(tmp1) + stoi(tmp2);
	int MIN = stoi(tmp3) + stoi(tmp4);
	cout << MIN << " " << MAX;
	return 0;

}