#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> v;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = (int)pow(i, 2);
		if (tmp >= m && tmp <= n) {
			v.push_back(tmp);
			sum += tmp;
		}
	}

	if (v.empty()) {
		printf("-1");
		return 0;
	}
	printf("%d\n", sum);
	printf("%d", v.front());

	return 0;
	
}