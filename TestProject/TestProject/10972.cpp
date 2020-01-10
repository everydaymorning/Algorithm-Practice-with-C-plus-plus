#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int tmp_check = n;
	int tmp_num = arr[n];
	for (int i = n; i >= 2; i--) {
		if (arr[i] > arr[i - 1]) {
			tmp_check = i - 1;
			tmp_num = arr[i - 1];
			break;
		}
	}

	if (tmp_check == n) {
		printf("-1");
		return 0;
	}

	for (int i = n; i > tmp_check; i--) {
		if (tmp_num < arr[i]) {
			swap(arr[tmp_check], arr[i]);
			
			break;
		}
	}
	sort(arr + tmp_check + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}