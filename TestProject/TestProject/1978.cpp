#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i] == 1) {
			continue;
		}
		int pn = 0;
		for (int j = 1; j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				pn++;
			}
			
		}

		if (pn == 2) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}