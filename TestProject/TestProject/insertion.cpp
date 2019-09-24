#include <iostream>

using namespace std;

int main() {
	int arr[10] = { 26, 5, 37, 1, 61, 11, 59, 15, 48 ,19};
	int i, j, tmp;
	for (i = 0; i < 9; i++) {
		j = i;
		while (j>0 && arr[j-1] > arr[j])
		{
			tmp = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = tmp;
			j--;
		}
		for (j = 0; j <= i; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}

	/*for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}*/

	return 0;
}