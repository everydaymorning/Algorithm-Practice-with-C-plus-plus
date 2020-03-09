#include <bits/stdc++.h>
using namespace std;
int n;
int arr[51];
int arr1[51];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		
	}
	sort(arr, arr + n);
	sort(arr1, arr1 + n, cmp);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] * arr1[i];
	}
	cout << sum;
	return 0;

}