#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size() - 2; j++) {
			if (str[j] == 'F' && str[j+1] == 'B' && str[j + 2] == 'I') {
				v.push_back(i + 1);
				break;
			}
		}
	}
	if (v.empty()) {
		cout << "HE GOT AWAY!";
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
	}
	return 0;
}