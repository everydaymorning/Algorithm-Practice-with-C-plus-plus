#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int total = 0;
	int res = 0;

	for (int i = 0; i < n; i++) {
		total += (i + 1);
		res += arr[i];
	}
	total += n + 1;
	total -= res;
	cout << total;
	return 0;
}