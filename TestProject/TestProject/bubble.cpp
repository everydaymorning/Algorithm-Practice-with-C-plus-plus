#include <iostream>

int main() {
	
	int arr[10] = { 1,4,10,3,2,7,9,5,8,6 };
	int tmp;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}