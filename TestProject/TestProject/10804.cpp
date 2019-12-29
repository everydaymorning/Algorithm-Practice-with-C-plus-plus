#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	for (int i = 0; i < 10; i++) {
		int start, end;
		cin >> start >> end;

		reverse(arr + start - 1, arr + end);
	}
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}