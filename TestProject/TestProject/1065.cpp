#include <bits/stdc++.h>
using namespace std;

int cnt;
void func(int n) {
	
	if (n > 0 && n < 100) {
		cnt++;
	}
	else if (n > 100) {
		int one = n / 100;
		int two = n % 100 / 10;
		int three = n % 100 % 10;
		if (one - two == two - three) {
			cnt++;
		}
	}
	else if (n == 1000) return;
	
}
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		func(i);
	}

	printf("%d", cnt);

	return 0;
}