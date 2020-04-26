#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int MAX = -2147483647;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = arr[i];
		MAX = max(MAX, sum);
		for (int j = i + 1; j < n; j++) {
			sum += arr[j];
			MAX = max(MAX, sum);
		}
	}
	cout << MAX;
	return 0;
}