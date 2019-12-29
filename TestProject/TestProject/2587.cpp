#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 5);

	printf("%d\n", sum / 5);
	printf("%d", arr[2]);

	return 0;
}