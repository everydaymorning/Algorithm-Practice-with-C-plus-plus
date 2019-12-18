#include <bits/stdc++.h>
using namespace std;
int s[1001][3];
int d[1001][3];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
		
	}
	d[0][0] = s[0][0];
	d[0][1] = s[0][1];
	d[0][2] = s[0][2];

	for (int i = 1; i < n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + s[i][0]; // 89	
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + s[i][1]; // 86
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + s[i][2]; // 83
	}

	printf("%d", min(min(d[n-1][0], d[n-1][1]), d[n-1][2]));

	return 0;
}