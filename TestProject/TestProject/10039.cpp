#include <bits/stdc++.h>
using namespace std;
int arr[5];
int sum;
int avg;
int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] < 40) {
			arr[i] = 40;
		}
		sum += arr[i];
	}
	avg = (int)sum / 5;
	cout << avg;
	return 0;
}