#include <bits/stdc++.h>

using namespace std;
int s[1001];
int d[1001];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	d[0] = 1;

	for (int i = 1; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (s[i] > s[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	printf("%d", *max_element(d, d + n));
	return 0;
}