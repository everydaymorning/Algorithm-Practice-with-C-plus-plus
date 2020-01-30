#include <bits/stdc++.h>
using namespace std;

// 공유기 설치 BOJ 2110 이분탐색을 이용한 최대 거리 찾기
// 이와 비슷한 최댓값을 찾는 이분 탐색 문제를 몇 개 푼 적이 있었는데도 이분 탐색을 이용한 문제인지 몰랐다.
// 이분 탐색을 이용하는 것을 확인하고도 어떻게 접근해야 할지 막막했다.
// 
int arr[200002];
int n, c;
int res;
bool possible(int mid) {
	int cnt = 1;
	int prev = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - prev >= mid) {
			cnt++;
			prev = arr[i];
		}
	}
	if (cnt >= c) {
		return true;
	}
	else {
		return false;
	}
}
int binaryS(int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (possible(mid)) {
			res = max(res, mid);
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
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int low = 1;
	int high = arr[n - 1] - arr[0];

	cout << binaryS(low, high);
	return 0;

}