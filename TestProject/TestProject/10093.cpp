#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long num;
	if (a > b) {
		num = a - b - 1;
		printf("%lld\n", num);
		for (long long i = b + 1; i < a; i++) {
			printf("%lld ", i);
		}
	}
	else if (a == b) {
		num = 0;
		printf("%lld\n", num);
	}
	else if(b > a){
		num = b - a - 1;
		printf("%lld\n", num);
		for (long long i = a + 1; i < b; i++) {
			printf("%lld ", i);
		}
	}

	return 0;
}