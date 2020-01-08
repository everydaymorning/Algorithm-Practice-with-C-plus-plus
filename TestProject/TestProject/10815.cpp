#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		
		if (binary_search(arr, arr + n, t)) cout << "1" << ' ';
		else cout << "0" << ' ';

	}

	return 0;
}