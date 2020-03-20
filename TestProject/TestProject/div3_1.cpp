#include <iostream>
#include <vector>
using namespace std;
int arr[101];
int t, n;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int MIN = 101;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] < MIN) {
				MIN = arr[i];
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			arr[i] -= MIN;
			if (arr[i] % 2 == 1) flag = true;
		}
		if (flag) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}

	}
	return 0;
}