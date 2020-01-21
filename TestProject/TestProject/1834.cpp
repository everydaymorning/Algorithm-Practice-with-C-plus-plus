#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		sum += (long long)n * i + i;
	}
	cout << sum;
	return 0;
}