#include <bits/stdc++.h>
using namespace std;

int main() {
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	
	int alpha1[26] = { 0 };
	int alpha2[26] = { 0 };

	int str1_size = str1.size();
	int str2_size = str2.size();

	for (int i = 0; i < str1_size; i++) {
		alpha1[str1.at(i) - 'a']++;
	}
	for (int i = 0; i < str2_size; i++) {
		alpha2[str2.at(i) - 'a']++;
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha1[i] != alpha2[i]) {
			cnt += abs(alpha1[i] - alpha2[i]);
		}
	}
	
	printf("%d", cnt);

	return 0;
}