#include <bits/stdc++.h>
using namespace std;
int arr[1001];
vector<int> lis;
int _lower(int s, int e, int target) {
	int mid = 0;
	while (e - s > 0) {
		mid = (s + e) / 2;

		if (lis[mid] < target) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}
	return e + 1;
}
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0;
	int j = 0;

	lis.push_back(arr[i]);
	i++;
	while (i < n) {

		if (lis.back() < arr[i]) {
			lis.push_back(arr[i]);
			j++;
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			lis[idx] = arr[i];
		}
		
		i++;
	}

	cout << lis.size();
	return 0;
}