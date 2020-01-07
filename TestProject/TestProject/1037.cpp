#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int res = arr[0] * arr[n - 1];
	printf("%d", res);

	return 0;
}