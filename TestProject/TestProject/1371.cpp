#include <bits/stdc++.h>
using namespace std;
int cnt[27];
int main() {

	while (!cin.eof()) {
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') continue;
			cnt[str[i] - 'a']++;
		}
	}
	int MAX = 0;
	int idx = 0;
	vector<int> v;
	for (int i = 0; i < 27; i++) {
		if (MAX < cnt[i]) {
			MAX = cnt[i];
		}
	}
	for (int i = 0; i < 27; i++) {
		if (cnt[i] == MAX) v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << (char)(v[i] + 'a');
	}
	
	return 0;
}