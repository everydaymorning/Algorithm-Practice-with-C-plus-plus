#include <bits/stdc++.h>
using namespace std;

int main() {

	int arr[43] = { 0 };
	for (int i = 0; i < 10; i++) {
		int t;
		cin >> t;

		int tmp = t % 42;
		arr[tmp]++;
	}
	int cnt = 0;
	for (int i = 0; i < 43; i++) {
		if (arr[i] > 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}