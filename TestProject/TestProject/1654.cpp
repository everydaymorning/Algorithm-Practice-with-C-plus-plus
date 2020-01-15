#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];

int k, n;
long long res;
long long binary_func(long long start, long long end) {
	while (start <= end) {
		long long mid = (start + end) / 2;
		cout << "start: " << start << "   end: " << end << '\n';
		cout << "mid: " << mid << '\n';
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			if (arr[i] >= mid) {
				sum += (arr[i] / mid);
			}
		}
		cout << "sum: " << sum << '\n';
		if (sum >= n) { // 자른 갯수가 필요한 랜선의 갯수보다 크거나 같으면
			if (res < mid) { 
				res = mid; // 최대 랜선의 길이 저장
				cout << "res: " << res << '\n';
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	long long mx = *max_element(arr, arr + k);
	sort(arr, arr + k);
	long long result = binary_func(1, mx);
	cout << result;

	return 0;

}