#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int arr[1001] = { 0 };
		int sum = 0;
		double avg = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		avg = (double)sum / n;
		double num = 0;
		for (int i = 0; i < n; i++) {
			if (avg < arr[i]) {
				num++;
			}
		}
		double avg_std = num / n * 100;
		char tmp = '%';
		printf("%.3f%c\n", avg_std, tmp);
	}
}