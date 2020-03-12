#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == v[i-1]) continue;
		cnt += abs(i - v[i - 1]);
	}
	cout << cnt;
	return 0;
}