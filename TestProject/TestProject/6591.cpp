#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n, k;
	
	while (1) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		
		int div = 1;
		long long res = 1;

		if (n - k < k) k = n - k; // nCk = nCn-k

		while (k-- > 0) {
			res *= n--;
			res /= div++;
		}

		cout << res << '\n';

	}
	

	return 0;

}