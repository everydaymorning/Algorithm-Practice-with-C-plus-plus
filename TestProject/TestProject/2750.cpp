#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	
	

	return 0;
}