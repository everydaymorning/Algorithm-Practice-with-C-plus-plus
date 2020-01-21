#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++) {
		if (abs(sum + arr[i] - 100) <= abs(sum - 100)) {
			sum += arr[i];
		}
		else {
			break;
		}
	}
	cout << sum;
	return 0;
	

}