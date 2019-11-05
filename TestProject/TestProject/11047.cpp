#include <iostream>

using namespace std;

int main() {
	int n, k;
	int cnt = 0;
	int won[10] = { 0 };
	int tmp = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> won[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k == 0) {
			break;
		}
		if (k / won[i] == 0) {
			continue;
		}
		else if (k / won[i] > 0) {
			tmp = k / won[i];
			cnt += tmp;
			k = k - (tmp * won[i]);
		}


	}

	printf("%d", cnt);

	return 0;
}