#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		
		if (binary_search(arr, arr + n, a)) {
			cout << "1" << '\n';
		}
		else {
			cout << "0" << '\n';
		}

	}

	return 0;
}