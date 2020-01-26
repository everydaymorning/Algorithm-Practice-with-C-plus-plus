#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += (int)pow(arr[i], 2);
	}
	int r = sum % 10;
	cout << r;
	return 0;
}