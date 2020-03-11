#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	n -= k;
	k--;
	int cnt = 1;
	while (1) {
		
		if (n <= 0) break;
		n -= k;
		cnt++;
	}
	cout << cnt;
	return 0;
}