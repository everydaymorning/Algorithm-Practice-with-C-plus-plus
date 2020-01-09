#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int check[8001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int sum = 0;
	int mid = n / 2;
	int mx = -4000;
	int mn = 4000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		sum += arr[i];
		check[arr[i] + 4000]++;
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
		
	}
	double avg = (double)sum / n;
	
	int range = mx - mn;
	
	int cur = 0;
	int num = -1;
	bool second = false;
	for (int i = 0; i <= 8001; i++) {
		if (cur < check[i]) {
			cur = check[i];
			num = i;
			second = true;
		}
		else if (cur == check[i] && second) {
			num = i;
			second = false;
		}
	}

	sort(arr, arr + n);

	cout << round(avg) << '\n';
	cout << arr[mid] << '\n';
	cout << num - 4000 << '\n';
	cout << range;

	return 0;

}