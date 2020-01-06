#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	vector<int> v;

	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			v.push_back(i);
		}
	}

	int mx = v.back();
	printf("%d\n", mx);

	int mn = (a * b) / mx;
	printf("%d", mn);

	return 0;
}