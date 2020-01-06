#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	vector<int> v;

	while (1) {
		int r = a % b;
		v.push_back(r);
		a /= b;
		if (a == 0) break;

	}

	reverse(v.begin(), v.end());

	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		if (v.at(i) < 10) {
			cout << v.at(i);
		}
		else {
			char c = v.at(i) - 10 + 'A';
			cout << c;
		}
	}

	return 0;
}