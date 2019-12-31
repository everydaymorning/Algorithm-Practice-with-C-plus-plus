#include <bits/stdc++.h>
using namespace std;

int arr[1001];
double arr2[1001];
int main() {
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (mx < arr[i]) {
			mx = arr[i];
		}
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		
		arr2[i] = (double)arr[i] / mx * 100;
		sum += arr2[i];
	}

	double avg = sum / n;
	printf("%f", avg);

	return 0;
}