#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	int search;
	cin >> search;
	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		if (v.at(i) == search) cnt++;
	}
	printf("%d", cnt);

	return 0;
}