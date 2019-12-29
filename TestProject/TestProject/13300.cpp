#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	int arr[2][7] = { 0 };
	int cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;
		arr[s][y]++;
	}

	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 2; j++) {
			int room = 0;
			if (arr[j][i] == 0) {
				room = 0;
			}
			else if (arr[j][i] <= k) {
				room = 1;
			}
			else if (arr[j][i] > k) {
				if (arr[j][i] % k == 0) {
					room = arr[j][i] / k;
				}
				else {
					room = arr[j][i] / k + 1;
				}
			}
			cnt += room;
		}
		
	}

	printf("%d", cnt);

	return 0;
}