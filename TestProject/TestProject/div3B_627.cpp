#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[5001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		bool flag = false;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 2; j < n; j++) {
				if (arr[i] == arr[j]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}