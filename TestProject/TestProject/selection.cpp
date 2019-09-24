#include <iostream>

using namespace std;

int main() {
	int min, index, tmp;
	int arr[10] = { 1,4,10,8,5,6,2,9,3,7 };
	
	for (int i = 0; i < 10; i++) {
		min = 9999;
		for (int j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}