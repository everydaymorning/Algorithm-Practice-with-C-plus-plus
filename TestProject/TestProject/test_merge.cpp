#include <bits/stdc++.h>
using namespace std;

void merge_(int h, int m, int* U, int* V, int* arr) {
	int i, j, k;
	i = j = k = 0;

	while (i < h && j < m) {
		if (U[i] < V[j]) {
			arr[k] = U[i];
			i++;
		}
		else {
			arr[k] = V[j];
			j++;
		}
		k++;
	}
	cout << "i: " << i << "   j: " << j << "  k: " << k << '\n';
	if (i > h) {
		for (int a = j; a < m; a++) {
			arr[k] = V[a];
			k++;
		}
	}
	else {
		for (int a = i; a < h; a++) {
			arr[k] = U[a];
			k++;
		}
	}
}
void mergeSort(int n, int* arr) {
	if (n > 0) {
		const int h = n / 2;
		const int m = n - h;
		int U[4] = { 0 };
		int V[4] = { 0 };

		cout << "h: " << h << "  m: " << m << '\n';
		cout << "U" << '\n';

		for (int i = 0; i < h; i++) {
			U[i] = arr[i];
			cout << U[i] << " ";
		}
		cout << '\n';
		cout << "V" << '\n';
		int j = 0;
		for (int i = m; i < n; i++) {
			V[j] = arr[i];
			cout << V[j] << " ";
			j++;
		}
		cout << '\n';
		mergeSort(h, U);
		mergeSort(m, V);
		merge_(h, m, U, V, arr);
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
}
int main() {
	int n = 8;
	int arr[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };
	mergeSort(n, arr);
	return 0;
}