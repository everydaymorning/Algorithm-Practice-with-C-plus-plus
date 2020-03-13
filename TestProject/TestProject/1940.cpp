#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
vector<int> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] + v[j] == m) cnt++;
		}
	}
	cout << cnt;
	return 0;
}