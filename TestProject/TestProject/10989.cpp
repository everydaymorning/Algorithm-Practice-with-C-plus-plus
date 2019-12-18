#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[t-1]++;
	}
	int cnt = 0;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cnt++;
			cout << i+1 << '\n';
			if (cnt == n) return 0;
		}
	}

	

	return 0;

}