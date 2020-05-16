#include <bits/stdc++.h>
using namespace std;
int s[10001];
int d[10001];
int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	d[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = s[i]; j <= k; j++) {
			cout << "i: " << i << "  j: " << j << '\n';
			if (j >= s[i]) {
				cout << "j: " << j << "  d[j - s[i]]: " << d[j - s[i]] << '\n';
				d[j] = d[j] + d[j - s[i]];
			}
		}
	}

	printf("%d", d[k]);
	return 0;
}