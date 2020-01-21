#include <bits/stdc++.h>
using namespace std;

int temp[100001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	int cur = 0;
	for (int i = 0; i < k; i++) {
		cur += temp[i];
	}
	int mx = cur;

	for (int i = k; i < n; i++) {
		cur -= temp[i - k];
		cur += temp[i];
		mx = max(mx, cur);
	}

	cout << mx;
	return 0;
}