#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
bool check[MAX];

int func(int n) {
	int ans = n;

	while (n) {
		ans += n % 10;
		n /= 10;
	}
	return ans;
	
}
int main() {

	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 1; i < MAX; i++) {
		int num = func(i);

		if (num < MAX) {
			check[num] = true;
		}
	}
	for (int i = 1; i < MAX; i++) {
		if (!check[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}