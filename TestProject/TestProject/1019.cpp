#include <bits/stdc++.h>
using namespace std;
long long arr[10];
void func(long long n) {
	if (n == 0) return;

	string str = to_string(n);
	int str_len = str.length();
	for (int i = 0; i < str_len; i++) {
		int a = str[i] - '0';
		arr[a]++;
	}

	func(n - 1);
	//½ÇÆÐ
	
}
int main() {

	long long q;
	cin >> q;
	
	func(q);
	for (int i = 0; i < 10; i++) {
		printf("%lld ", arr[i]);
	}

	return 0;
}