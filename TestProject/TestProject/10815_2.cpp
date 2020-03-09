#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int n, m;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (binary_search(arr, arr + n, a)) {
			cout << "1" << " ";
		}
		else cout << "0" << " ";
	}
	return 0;
}