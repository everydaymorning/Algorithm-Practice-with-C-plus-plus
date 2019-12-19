#include <bits/stdc++.h>
using namespace std;
int s[100001];
int d[100001];
int main() {
	int n;
	cin >> n;

	

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	d[1] = s[1];
	for (int i = 2; i <= n; i++) {
		d[i] = max(0, d[i - 1]) + s[i];
		
	}

	printf("%d", *max_element(d + 1, d + n + 1));
	return 0;
}