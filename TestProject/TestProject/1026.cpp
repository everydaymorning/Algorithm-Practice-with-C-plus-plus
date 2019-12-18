#include <bits/stdc++.h>
using namespace std;
int arr1[51];
int arr2[51];
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		arr1[i] = tmp;
	}

	for (int i = 0; i < t; i++) {
		int tmp;
		cin >> tmp;
		arr2[i] = tmp;
	}
	
	sort(arr1, arr1 + t);
	sort(arr2, arr2 + t, greater<int>());

	int sum = 0;
	for (int i = 0; i < t; i++) {
		sum += arr1[i] * arr2[i];
	}

	printf("%d", sum);

	return 0;
}