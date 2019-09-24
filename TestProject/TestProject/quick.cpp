#include <iostream>

int data[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
int number = 10;

void quicksort(int* data, int start, int end);
void show();

int main() {
	quicksort(data, 0, number - 1);
	show();
	return 0;
}

void quicksort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int tmp;

	while (i <= j) {
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (j > start && data[j] >= data[key]) {
			j--;
		}

		if (i > j) {
			tmp = data[j];
			data[j] = data[key];
			data[key] = tmp;
		}
		else {
			tmp = data[i];
			data[i] = data[key];
			data[key] = tmp;
		}
	}

	quicksort(data, start, j - 1);
	quicksort(data, j + 1, end);
}

void show() {
	for (int i = 0; i < number; i++) {
		printf("%d ", data[i]);
	}
}