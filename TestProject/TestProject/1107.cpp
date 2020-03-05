#include <bits/stdc++.h>
using namespace std;
bool broken[10];
int n, m;

int possible(int a) {

	if (a == 0) {
		if (broken[a]) return 0;
		else return 1;
	}

	int len = 0;

	while (a > 0) {
		if (broken[a % 10]) return 0;
		len += 1;
		a /= 10;
	}

	return len;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}
	int res = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {
		int tmp = i;
		int tmp_res = 0;
		if (possible(tmp)) {
			tmp_res = possible(tmp) + abs(n - tmp);
		}
		else {
			tmp_res = abs(n - 100);
		}

		res = min(res, tmp_res);

	}

	cout << res;
	return 0;
}