#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int arr2[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < m; i++) {
			bool flag = false;
			if (binary_search(arr, arr + n, arr2[i])) {
				flag = true;
			}
			if (flag) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}

	}

	return 0;
}