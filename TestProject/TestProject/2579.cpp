#include <bits/stdc++.h>
using namespace std;

int d[301][3];
int s[301];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		s[i] = t;
	}

	d[1][1] = s[1];
	d[1][2] = 0;

	for (int i = 2; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
		d[i][2] = d[i-1][1] + s[i];
	}

	printf("%d", max(d[n][1], d[n][2]));

	return 0;
}