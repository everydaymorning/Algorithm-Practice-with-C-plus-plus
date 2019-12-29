#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str1, str2;
		cin >> str1 >> str2;

		int alpha1[26] = { 0 };
		int alpha2[26] = { 0 };

		int str1_size = str1.size();
		int str2_size = str2.size();

		for (int j = 0; j < str1_size; j++) {
			alpha1[str1[j] - 'a']++;
			alpha2[str2[j] - 'a']++;
		}
		bool flag = false;
		for (int j = 0; j < 26; j++) {
			if (alpha1[j] != alpha2[j]) {
				flag = true;
			}
		}

		if (flag) {
			printf("Impossible\n");
		}
		else {
			printf("Possible\n");
		}

		for (int j = 0; j < 26; j++) {
			alpha1[j] = 0;
			alpha2[j] = 0;
		}

	}

	return 0;
}