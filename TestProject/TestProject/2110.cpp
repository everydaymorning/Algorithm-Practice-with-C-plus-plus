#include <bits/stdc++.h>
using namespace std;

// ������ ��ġ BOJ 2110 �̺�Ž���� �̿��� �ִ� �Ÿ� ã��
// �̿� ����� �ִ��� ã�� �̺� Ž�� ������ �� �� Ǭ ���� �־��µ��� �̺� Ž���� �̿��� �������� ������.
// �̺� Ž���� �̿��ϴ� ���� Ȯ���ϰ� ��� �����ؾ� ���� �����ߴ�.
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