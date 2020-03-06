#include <bits/stdc++.h>
using namespace std;
long long s, sum, cnt;
int main() {
	cin >> s;
	
	for (int i = 1; sum <= s; i++) {
		if (sum + i<= s) {
			sum += i;
			cnt++;
		}
		else {
			cout << cnt;
			break;
		}
	}

	return 0;
}