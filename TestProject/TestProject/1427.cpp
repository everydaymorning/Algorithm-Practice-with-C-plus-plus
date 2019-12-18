#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str = to_string(n);
	vector<int> v;
	int str_size = str.size();

	for (int i = 0; i < str_size; i++) {
		v.push_back(str.at(i) - '0');
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < str_size; i++) {
		printf("%d", v.at(i));
	}

	return 0;
}