#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[8] = { 0 };
	int idx = 0;
	int sum = 0;
	int min = 999;
	for (int i = 0; i < 7; i++) {
		int t;
		cin >> t;
		if (t % 2 == 1) {
			arr[idx++] = t;
			sum += t;
			
		}
	}

	if (sum == 0) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < idx; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	printf("%d\n", sum);
	printf("%d", min);

	return 0;
	
}