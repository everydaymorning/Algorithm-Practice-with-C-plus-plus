#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	printf("%d %d", arr[0], arr[n - 1]);

	return 0;
}