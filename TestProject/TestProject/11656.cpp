#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	cin >> str;
	vector<string> v;
	int str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		v.push_back(str.substr(i));
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < str_size; i++) {
		cout << v.at(i) << '\n';
	}


	return 0;
}